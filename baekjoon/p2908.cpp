#include <iostream>

/*
* Problem
*     각 자릿수가 0이 아닌 세자리 숫자가 두 개 주어진다
*     각 숫자를 뒤집어서 배열한 후, 더 큰 수를 출력하여라
*
* Ideas
*     자릿수가 지정되어 있으니 쉬워보인다, 있는 그대로 구현하자
*
* Comments
*/

using namespace std;

int main() {
	int		a, b, first, second, third;

	cin >> a >> b;
	first = a/100 ; second = a/10%10 ; third = a%10 ;
	a = third*100 + second*10 + first;
	first = b/100 ; second = b/10%10 ; third = b%10 ;
	b = third*100 + second*10 + first;
	
	if (a > b) cout << a;
	else cout << b;
}