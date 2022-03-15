#include <iostream>

/*
* Problem
*     alphanumeric 문자로 이루어진 문자열이 들어올 때, 각 문자를 r번 반복하여 만들어진 문자를 출력하라
*
* Ideas
*     for문으로 반복하자
*
* Comments
*/

using namespace std;

int main() {
	int		n, r;
	string	str;

	cin >> n;
	for (int i=0 ; i<n ; i++) {
		cin >> r >> str;
		for (int idx=0 ; idx<str.length() ; idx++) { 
			for (int jdx=0 ; jdx<r ; jdx++)cout << str[idx];
		}
		cout << "\n";
	}
}