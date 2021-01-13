#include <iostream>
#include <queue>

using namespace std;

int				maps[500][500], n, m, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int				cnts[500][500];
priority_queue<pair<int, pair<int, int> > >		pq;
pair<int, pair<int, int> >						ppr;

int		is_valid(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m)
		return (0);
	return (1);
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> maps[i][j];
		}
	}
	pq.push(make_pair(maps[0][0], make_pair(0, 0)));
	cnts[0][0] = 1;
	while (pq.size())
	{
		ppr = pq.top();
		pq.pop();
		for (int i = 0; i < 4; i++)
		{
			int		x = ppr.second.first;
			int		y = ppr.second.second;
			int		nextx = x + dx[i];
			int		nexty = y + dy[i];
			if (is_valid(nextx, nexty))
			{
				if (maps[x][y] > maps[nextx][nexty])
				{
					if (cnts[nextx][nexty] == 0)
						pq.push(make_pair(maps[nextx][nexty], make_pair(nextx, nexty)));
					cnts[nextx][nexty] += cnts[x][y];
				}
				if (nextx == n - 1 && nexty == m - 1)
					break ;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << cnts[i][j] << " ";
		}
		cout << "\n";
	}
	cout << cnts[n - 1][m - 1];
	return (0);
}