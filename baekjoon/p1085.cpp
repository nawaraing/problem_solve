#include <iostream>

/*
* Problem
*     https://www.acmicpc.net/problem/1085
*
* Ideas
*
* Comments
*/

using namespace std;

int main() {
	int		x, y, w, h, minn=2147483647;

	cin >> x >> y >> w >> h;
	if (minn > w-x) minn = w-x;
	if (minn > x) minn = x;
	if (minn > h-y) minn = h-y;
	if (minn > y) minn = y;
	cout << minn;
}