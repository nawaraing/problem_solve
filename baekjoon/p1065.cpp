#include <iostream>

/*
* Problem
*     각 자릿수가 등차수열을 이루는 수를 한수라고 한다
*     n<1000이 주어졌을 때, 1부터 n 사이 한수의 갯수를 구하여라
*
* Ideas
*     1~99까지는 모든 수가 한수이다
*     세자릿 수부터는 자릿수의 차이를 비교해서 한수를 판별하자
*
* Comments
*/

using namespace std;

int main() {
	int n, one, two, three, cnt=0;

	cin >> n;
	if (n < 100) cout << n;
	else {
		cnt = 99;
		for (int num=100 ; num<=n ; num++) {
			one = num%10; two = num/10%10; three = num/100;
			if (one-two == two-three) cnt++;
		}
		cout << cnt;
	}
}