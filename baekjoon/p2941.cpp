#include <iostream>
#include <cstring>

/*
* Problem
*     알파벳 2~3개를 이용하여 크로아티아 알파벳을 표현할 수 있다
*     크로아티아 알파벳이 섞인 단어가 주어질 때, 
*     단어가 몇 개의 알파벳으로 이루어져 있는 지, 출력하여라
*     단, 크로아티아 알파벳으로 표현할 수 있는 알파벳 조합은 모두 크로아티아 알파벳으로 판단하고,
*     크로아티아 알파벳은 하나의 알파벳으로 센다
*
* Ideas
*     배열에 크로아티아 알파벳을 미리 저장해둔다
*     단어의 각 자리를 돌면서 string::compare를 이용하여 비교하자
*
* Comments
*/

using namespace std;

# define ARR_SIZE 8

int main() {
	string		word;
	const char	*alpha[ARR_SIZE]={"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
	int			find_len=1, ans=0;

	cin >> word;
	for (int iWord=0 ; iWord<word.length() ; iWord += find_len) {
		find_len = 1;
		for (int iAlpha=0 ; iAlpha<ARR_SIZE ; iAlpha++) {
			// cout << "iWord:" << iWord << "     strlen(alpha[iAlpha]):" << strlen(alpha[iAlpha]) << "    alpha[iAlpha]:" << alpha[iAlpha] << "\n";
			if (word.compare(iWord, strlen(alpha[iAlpha]), alpha[iAlpha]) == 0) {
				if (iAlpha == 2) find_len = 3;
				else find_len = 2;
				break ;
			}
		}
		// cout << "ans:" << ans << "    find_len:" << find_len << "\n";
		ans++;
	}
	cout << ans;
}