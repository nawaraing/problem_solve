#include <iostream>
#include <stdio.h>

/*
* Problem
*     https://www.acmicpc.net/problem/10872
*
* Ideas
*
* Comments
*/

using namespace std;

int		main() {
	int		n, ans = 1;

	cin >> n;
	while (n--) ans *= n+1;
	cout << ans;
}