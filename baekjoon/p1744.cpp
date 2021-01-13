#include <iostream>
#include <queue>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int							n, a, b, sum = 0, zero = 0;
	priority_queue<int>			pos, neg;

	cin >> n;
	while (n--) {
		cin >> a;
		if (a == 0) zero = 1;
		else if (a == 1) sum++;
		else if (a > 0) pos.push(a);
		else neg.push(-a);
	}
	while ((int)pos.size() > 1) {
		a = pos.top();
		pos.pop();
		b = pos.top();
		pos.pop();
		sum += a * b;
	}
	if (pos.size()) sum += pos.top();
	while ((int)neg.size() > 1) {
		a = neg.top();
		neg.pop();
		b = neg.top();
		neg.pop();
		sum += a * b;
	}
	if (neg.size() && !zero) sum -= neg.top();
	cout << sum;
	return (0);
}