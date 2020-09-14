#include <iostream>
//#include <vector>
#include <queue>
//#include <stack>
//#include <list>
//#include <algorithm>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	queue<int>		q;
	int			t, n, a, turn, ans;

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a;
			q.push(a);
		}
		turn = 1;
		ans = 0;
		while (q.size()) {
			if (turn) {
				if (q.front())
					ans++;
				q.pop();
				if (q.size() && !q.front())
					q.pop();
				turn = 0;
			}
			else {
				q.pop();
				if (q.size() && q.front())
					q.pop();
				turn = 1;
			}
		}
		cout << ans;
		if (t != 0)
			cout << "\n";
	}
	return (0);
}
