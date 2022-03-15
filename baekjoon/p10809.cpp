#include <iostream>

/*
* Problem
*     알파벳 소문자로 이루어진 단어가 주어진다
*     각 알파벳이 처음 나온 위치를 출력하라
*     해당 알파벳이 등장하지 않으면 -1을 출력하라
*
* Ideas
*     알파벳 배열을 선언해서 -1로 초기화한 후, 주어진 문자의 알파벳을 순서대로 검색하자
*
* Comments
*/

using namespace std;

int main() {
	int		alpha[26];
	string	str;

	for (int i=0 ; i<26 ; i++) alpha[i] = -1;

	cin >> str;
	for (int i=0 ; i<str.length() ; i++)
		if (alpha[str[i] - 'a'] == -1) alpha[str[i] - 'a'] = i;
	
	for (int i=0 ; i<26 ; i++)
		cout << alpha[i] << " ";
}