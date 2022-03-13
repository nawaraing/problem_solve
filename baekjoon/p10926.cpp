#include <iostream>

/*
* Problem
*     입력으로 주어지는 문자열 뒤에 ??!를 붙여서 출력하라
*
* Ideas
*     iostream의 cin, cout을 사용하여 문제를 해결하겠다
*     
* Comments
*     'warning: trigraph ignored [-Wtrigraphs]'
*     c++에서는 '??'을 연달아서 쓸 수 없다고 한다
*     warning을 해결하기 위해 '\?\?'으로 수정해주었다
*/

using namespace std;

int main() {
	string id;

	cin >> id;
	cout << id << "\?\?!";
}