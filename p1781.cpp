#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int			n, a, b, ret;
pair<int, int>	pr;
priority_queue<pair<int, int> >		deadline;		//	* <deadline, ramen>
priority_queue<pair<int, int> >		ramen;			//	* <ramen, deadline>

bool	ft_sort(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return (a.second > b.second);
	}
	return (a.first > b.first);
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		deadline.push(make_pair(a, b));
	}
	for (int i = n; i > 0; i--) {
		while (deadline.size() && i == deadline.top().first) {
			pr = deadline.top();
			ramen.push(make_pair(pr.second, pr.first));
			deadline.pop();
		}
		if (ramen.size()) {
			ret += ramen.top().first;
			ramen.pop();
		}
	}
	cout << ret;
	return (0);
}