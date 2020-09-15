#include <iostream>
//#include <vector>
#include <queue>
//#include <stack>
#include <list>
#include <algorithm>
#include <utility>

using namespace std;

bool		ft_sort(int i, int j) {return i > j;}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			t, n, m, a, cnt;
	queue<pair<bool, int> > q;
	list<int>		val;

	cin >> t;
	while (t--) {
		cin >> n; cin >> m;
		cnt = 0;
		while (val.size()) val.pop_front();
		while (q.size()) q.pop();
		for (int i = 0; i < n; i++) {
			cin >> a;
			if (m == i)
				q.push(make_pair(1, a));
			else 
				q.push(make_pair(0, a));
			val.push_back(a);
		}
		val.sort(ft_sort);
		while (q.size()) {
			if (q.front().second < val.front()) {
				q.push(q.front());
				q.pop();
			}
			else {
				cnt++;
				if (q.front().first) break ;
				val.pop_front();
				q.pop();
			}
		}
		cout << cnt;
		if (t != 0) cout << "\n";
	}
	return (0);
}
