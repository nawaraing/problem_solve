#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

int									v, e, p, a, b, c, cost[5001];
bool								use[5001], flag;
priority_queue<pair<int, pair<int, bool> > >		pq;						//  < - 누적 cost, < dot, p? > >
vector<pair<int, int> >				graph[5001];			//  < dot, cost >
pair<int, pair<int, bool> >			tmp;
pair<int, int>						pr;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> v >> e >> p;
	while (e--) {
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	for (int i = 2; i <= v; i++) cost[i] = INT_MAX;
	if (p == 1) flag = 1;
	pq.push(make_pair(0, make_pair(1, flag)));
	cost[1] = 0;
	while (pq.size()) {
		tmp = pq.top();
		pq.pop();
		for (int i = 0; i < graph[tmp.second.first].size(); i++) {
			if (cost[graph[tmp.second.first][i].first] > -tmp.first + graph[tmp.second.first][i].second) {
				cost[graph[tmp.second.first][i].first] = -tmp.first + graph[tmp.second.first][i].second;
				flag = tmp.second.second;
				if (p == tmp.second.first) flag = 1;
				pq.push(make_pair(-cost[graph[tmp.second.first][i].first], make_pair(graph[tmp.second.first][i].first, flag)));
			}
		}
	}
	if ()
	return (0);
}