#include <iostream>
#include <queue>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long						t, n, a, b, cost = 0;
	priority_queue<long long>		pq;

	cin >> t;
	while (t--) {
		cin >> n;
		while (n--) {
			cin >> a;
			pq.push(-a);
		}
		cost = 1;
		while (pq.size() > 1) {
			a = -pq.top();
			pq.pop();
			b = -pq.top();
			pq.pop();
			a *= b;
			cost = a % 1000000007 * cost % 1000000007;
			pq.push(-a);
		}
		pq.pop();
		cout << cost;
		if (t) cout << "\n";
	}
	return (0);
}