#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int									n, m, a, b, c;
int									graph[1001][1001];
priority_queue<pair<int, int> >		pq;
pair<int, vector<int> >				cost[1001];
pair<int, int>						pr;
bool								visit[1001];
vector<int>							v;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n ; i++)
	{
		cost[i] = make_pair(2147483647, v);
		for (int j = 1; j <= n ; j++)
		{
			graph[i][j] = -1;
		}
	}
/* 	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <=n ; j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
 */	while (m--)
	{
		cin >> a >> b >> c;
		if (graph[a][b] == -1 || graph[a][b] > c)
			graph[a][b] = c;
	}
	cin >> a >> b;
	pq.push(make_pair(-0, a));
	cost[a].first = 0;
	while (pq.size())
	{
		pr = pq.top();
		pq.pop();
		// cout << "-cost : " << pr.first << "   node : " << pr.second << "\n";
		if (pr.second == b) break ;
		visit[pr.second] = true;
		for (int i = 1; i <= n; i++)
		{
			// cout << "graph["<<pr.second<<"]["<<i<<"] : " << graph[pr.second][i] << "\n" << "visit["<<i<<"] : " << visit[i] << "\n";
			if (graph[pr.second][i] == -1 || visit[i]) continue ;
			if (cost[i].first > graph[pr.second][i] + cost[pr.second].first)
			{
				cost[i].first = graph[pr.second][i] + cost[pr.second].first;
				v = cost[pr.second].second;
				v.push_back(pr.second);
				cost[i].second = v;
				pq.push(make_pair(-(cost[i].first), i));
			}
		}
	}
	cout << cost[b].first << "\n" << cost[b].second.size() + 1 << "\n";
	for (int i = 0 ; i < cost[b].second.size(); i++)
	{
		cout << (cost[b].second)[i] << " ";
	}
	cout << b;
	return (0);
}