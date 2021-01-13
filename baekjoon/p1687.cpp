#include <iostream>
#include <queue>

using namespace std;

int						n, k, bar[100001], tmp;
queue<int>				q;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	if (n >= k) {
		cout << n - k;
		return (0);
	}
	q.push(n);
	while (!bar[k]) {
		tmp = q.front();
		q.pop();
		if (tmp > 0 && !bar[tmp - 1]) {
			bar[tmp - 1] = bar[tmp] + 1;
			q.push(tmp - 1);
		}
		if (tmp < 100000 && !bar[tmp + 1]) {
			bar[tmp + 1] = bar[tmp] + 1;
			q.push(tmp + 1);
		}
		if (tmp && 2 * tmp < 100001 && !bar[2 * tmp]) {
			bar[2 * tmp] = bar[tmp] + 1;
			q.push(2 * tmp);
		}
	}
	cout << bar[k];
	return (0);
}