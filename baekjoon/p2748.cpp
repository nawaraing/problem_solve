#include <iostream>
#include <queue>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	unsigned long long 		n;
	queue<unsigned long long>	q;

	cin >> n;
	if (n == 0) {
		cout << 0;
		return (0);
	}
	else if (n == 1) {
		cout << 1;
		return (0);
	}
	q.push(0);
	q.push(1);
	while (n-- - 1) {
		q.push(q.front() + q.back());
		q.pop();
	}
	cout << q.back();
	return (0);
}
