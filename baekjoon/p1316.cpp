#include <iostream>

/*
* Problem
*     동일한 알파벳이 모두 붙어있는 경우 그룹 단어라고 한다
*     여러 단어가 입력으로 주어졌을 때, 그룹 단어의 갯수를 출력하여라
*
* Ideas
*     알파벳 배열을 선언하여 visit 체크를 하자
*
* Comments
*/

using namespace std;

int main() {
	bool	visit[26]={false,}, isGroup=true;
	int		n, ans=0;
	char	alpha;
	string	str;

	cin >> n;
	for (int iN ; iN<n ; iN++) {
		cin >> str;
		for (int iStr=0 ; iStr<str.length() ; iStr++) {
			alpha = str[iStr];
			if (visit[alpha-'a']) {isGroup=false ; break ;}
			visit[alpha-'a']=true;
			while (iStr+1 < str.length() && str[iStr] == str[iStr+1]) iStr++;
		}
		if (isGroup) ans++;
		else isGroup = true;
		for (int iVisit=0 ; iVisit<26 ; iVisit++) visit[iVisit] = false;
	}
	cout << ans;
}