#include <iostream>

/*
* Problem
*     퀴즈의 결과가 O, X의 문자열로 주어진다
*     문제를 맞춘 경우, 그 문제의 점수는 그 문제까지 연달아 나온 O의 갯수이다
*
* Ideas
*     for문으로 돌리자
*
* Comments
*/

using namespace std;

int main() {
	int		n;
	string	str;
	int		cnt=0, score=0;

	cin >> n;	
	for (int i=0; i<n; i++) {
		cin >> str;
		for (int idx=0; idx<str.length(); idx++) {
			if ('O' == str[idx]) {
				cnt++;
				score += cnt;
				// cout << "str:" << str << "    idx:" << idx << "    cnt:" << cnt << "\n";
			}
			else cnt=0;
		}
		cout << score << "\n";
		score = 0; cnt = 0;
	}
}