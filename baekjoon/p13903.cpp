#include <iostream>
#include <queue>

using namespace std;

int			r, c, road[1000][1000], visit[1000][1000], n;
int			walk[10][2];
priority_queue<pair<int, pair<int, int> > >		pq;
pair<int, pair<int, int> >						ppr;


int			can_go(int y, int x)
{
	if (y < 0 || y >= r || x < 0 || x >= c) return 0;
	if (visit[y][x]) return 0;
	if (road[y][x] == 0) return 0;
	return 1;
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> road[i][j];
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> walk[i][0] >> walk[i][1];
	}
	// if (r == 1)
	// {
	// 	for (int i = 0; i < c; i++)
	// 	{
	// 		if (road[0][i])
	// 		{
	// 			cout << 0;
	// 			return (0);
	// 		}
	// 	}
	// 	cout << -1;
	// 	return (0);
	// }
	for (int i = 0; i < c; i++)
	{
		if (road[0][i])
		{
			pq.push(make_pair(0, make_pair(0, i)));
			visit[0][i] = 1;
		}
	}
	int			flag = 0;
	while (pq.size())
	{
		ppr = pq.top();
		pq.pop();
		// cout << ppr.first << " " << ppr.second.first << " " << ppr.second.second << "\n";
		if (ppr.second.first == r - 1)
		{
			flag = 1;
			break ;
		}
		for (int i = 0; i < n; i++)
		{
			int		nextx = ppr.second.first + walk[i][0];
			int		nexty = ppr.second.second + walk[i][1];
			if (can_go(nextx, nexty))
			{
				visit[nextx][nexty] = 1;
				pq.push(make_pair(ppr.first - 1, make_pair(nextx, nexty)));
			}
		}
	}
	if (flag) cout << -ppr.first;
	else cout << -1;
	return (0);
}