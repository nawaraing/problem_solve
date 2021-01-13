#include <iostream>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

int								visit[20001];
int								cost[20001];
vector<pair<int, int> >			vec[20001];		// <default cost, v>
priority_queue<pair<int, int> >	pq;				// <-cost, v>

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		v, e, k, a, b, c;
	pair<int, int>	pr;

	cin >> v >> e >> k;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		vec[a].push_back(make_pair(c, b));
	}
	for (int i = 1; i <= v; i++) {
		cost[i] = 2147483647;
	}
	pq.push(make_pair(0, k));
	cost[k] = 0;
	while (pq.size()) {
		pr = pq.top();
		pq.pop();
		visit[pr.second] = 1;
		for (int i = 0; i < vec[pr.second].size(); i++) {
			if (!visit[vec[pr.second][i].second] && cost[vec[pr.second][i].second] > cost[pr.second] + vec[pr.second][i].first)
			{
				cost[vec[pr.second][i].second] = cost[pr.second] + vec[pr.second][i].first;
				pq.push(make_pair(-cost[vec[pr.second][i].second], vec[pr.second][i].second));
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		if (cost[i] != 2147483647) cout << cost[i];
		else cout << "INF";
		if (i != v) cout << "\n";
	}
	return (0);
}