#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int				n, m, j, k, a, b, dist, cost[5001];
bool			A[5001], B[5001], visit[5001];
vector<pair<int, int> >		graph[5001];
pair<int, int>				pr, tmp;
queue<pair<int, int> >					q;
pair<int, char>			minn;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> j >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> a;
		A[a] = true;
	}
	for (int i = 0; i < k; i++)
	{
		cin >> a;
		B[a] = true;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> dist;
		graph[a].push_back(make_pair(b, dist));
		graph[b].push_back(make_pair(a, dist));
	}
	for (int i = 1; i <= n; i++)
	{
		cost[i] = INT_MAX;
	}
	minn.first = INT_MAX;
	minn.second = 0;
	q.push(make_pair(j, 0));
	visit[j] = true;
	cost[j] = 0;
	while (!q.empty())
	{
		pr = q.front();
		q.pop();
		cout << pr.first << " " << pr.second << "\n";
		for (int i = 0; i < graph[pr.first].size(); i++)
		{
			cout << graph[pr.first][i].first << " ";
			tmp = graph[pr.first][i];
			if (!visit[tmp.first])
			{
				visit[tmp.first] = true;
				cout << A[tmp.first] << " " << B[tmp.first] << "\n";
				if (!A[tmp.first] && !B[tmp.first])
				{
					q.push(tmp);
					if (cost[tmp.first] > cost[pr.first] + tmp.second)
						cost[tmp.first] = cost[pr.first] + tmp.second;
				}
				else
				{
					if (minn.first > cost[pr.first] + tmp.second)
					{
						if (A[tmp.first])
							minn = make_pair(cost[pr.first] + tmp.second, 'A');
						else
						{
							minn = make_pair(cost[pr.first] + tmp.second, 'B');
						}
					}
				}
			}
		}
	}
	if (minn.second == 0)
		cout << -1;
	else
		cout << minn.second << "\n" << minn.first;
	return (0);
}