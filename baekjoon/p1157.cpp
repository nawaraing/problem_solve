#include <iostream>

/*
* Problem
*     알파벳 대소문자로 이루어진 문자열이 주어졌을 때,
*     대소문자 구분없이 가장 많이 등장한 알파벳을 대문자로 출력하여라
*     가장 많이 등장한 알파벳이 여러 개일 때는 '?'를 출력한다
*
* Ideas
*     알파벳 배열을 선언하고 발생 횟수를 카운트하자 
*
* Comments
*/

using namespace std;

int main() {
	int		alpha[26]={0,}, cnt=0, many=0;
	string	str;
	char	ans;

	cin >> str;
	for (int i=0 ; i<str.length() ; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') alpha[str[i] - 'a']++;
		else alpha[str[i] - 'A']++;
	}
	// for (int i=0 ; i<26 ; i++) cout << alpha[i] << " ";
	for (int i=0 ; i<26 ; i++) {
		if (many < alpha[i]) {
			many = alpha[i];
			ans = i + 'A';
			cnt = 1;
		} else if (many == alpha[i]) {
			cnt++;
		}
	}
	if (cnt > 1) cout << "?";
	else if (cnt == 1) cout << ans;
	else cout << "error";
}