#include <iostream>

/*
* Problem
*     https://www.acmicpc.net/problem/10870
*
* Ideas
*
* Comments
*/

using namespace std;

int		main() {
	int		n, fibo[21];

	fibo[0] = 0; fibo[1] = 1;

	cin >> n;
	for (int iN = 2; iN <= n; iN++) fibo[iN] = fibo[iN - 1] + fibo[iN - 2];
	cout << fibo[n];
}