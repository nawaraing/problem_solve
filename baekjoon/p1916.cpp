#include <iostream>
#include <limits.h>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

typedef unsigned long long ull;

vector<pair<int, int> >			graph[1001];
int								cost[1001];
priority_queue<pair<int, int> >	pq;

int				main(void)
{
	int			a, b, c, m, n;

	cin >> n >> m;
	while (m--) {
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(c, b));
	}
	for (int i = 1; i <= n; i++) {
		cost[i] = INT_MAX;
	}
	cin >> a >> b;
	pq.push(make_pair(0, a));
	while (!pq.empty()) {
		int		curr = pq.top().second;
		int		dist = -pq.top().first;
		pq.pop();
		for (int i = 0; i < graph[curr].size(); i++) {
			int		next = graph[curr][i].second;
			int		move_cost = graph[curr][i].first;
			if (cost[next] > dist + move_cost) {
				cost[next] = dist + move_cost;
				pq.push(make_pair(-(dist + move_cost), next));
			}
		}
	}
	cout << cost[b];
}