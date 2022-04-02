#include <iostream>
#include <queue>

/*
* Problem
*     https://www.acmicpc.net/problem/4153
*
* Ideas
*     피타고라스의 법칙을 이용한다
*
* Comments
*/

using namespace std;

int		main() {
	int		a, b, c;
	priority_queue<int>		pq;

	cin >> a >> b >> c;
	while (a != 0 || b != 0 || c != 0) {
		pq.push(a); pq.push(b); pq.push(c);
		c = pq.top(); pq.pop();
		b = pq.top(); pq.pop();
		a = pq.top(); pq.pop();

		if (a*a + b*b == c*c) cout << "right\n";
		else cout << "wrong\n";

		cin >> a >> b >> c;
	}
}