#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int		visit[200001], n, a, m;
vector<int>			graph[200001];
priority_queue<pair<int, int> >			pq; // < -time, node >

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		while (a != 0)
		{
			graph[i].push_back(a);
			cin >> a;
		}
		visit[i] = -1;
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a;
		pq.push(make_pair(0, a));
		visit[a] = 0;
	}
	while (pq.size())
	{
		pair<int, int>	pr = pq.top();
		pq.pop();
		if (visit[pr.second] != -1)
		{
			for (int i = 0; i < graph[pr.second].size(); i++)
			{
				int	next = graph[pr.second][i];
				if (visit[next] == -1)
					pq.push(make_pair(pr.first, next));
			}
		}
		else
		{
			int	cnt = 0;
			for (int i = 0; i < graph[pr.second].size(); i++)
			{
				int	next = graph[pr.second][i];
				// cout << pr.second << " : " << next << " " <<  visit[next] << " " << -pr.first << "\n";
				if (visit[next] != -1 && visit[next] <= -pr.first) cnt++;
			}
			if (2 * cnt >= graph[pr.second].size())
			{
				visit[pr.second] = -pr.first + 1;
				pq.push(make_pair(pr.first - 1, pr.second));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << visit[i];
		if (i != n) cout << " ";
	}
	return (0);
}