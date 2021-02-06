#include <iostream>
#include <queue>

using namespace std;

int			maps[1001][1001], visit[1001][1001][11][2], n, m, k, dx[5] = {0, 1, -1, 0, 0}, dy[5] = {0, 0, 0, 1, -1};
queue<pair<pair<int, int>, pair<int, int> > >		q;		// <<cnt, break>, <r, c>>

int		is_valid(int r, int c, int wall, int *ref, int cnt, int dir)
{
	if (r < 1 || r > n) return (0);
	if (c < 1 || c > m) return (0);
	if (dir != 0 && maps[r][c] == 1)
	{
		if (wall + 1 > k) return (0);
		if (cnt % 2 == 0) return (0);
		if (visit[r][c][wall + 1][cnt % 2] == 1) return (0);
		visit[r][c][wall + 1][cnt % 2] = 1;
		*ref = 1;
		return (1);
	}
	if (visit[r][c][wall][cnt % 2] == 1) return (0);
	visit[r][c][wall][cnt % 2] = 1;
	return (1);
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	char	c;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> c;
			if (c == '0') maps[i][j] = 0;
			else maps[i][j] = 1;
		}
	}
	if (n == 1 && m == 1)
	{
		cout << 1; return (0);
	}
	visit[1][1][0][0] = 1;
	q.push(make_pair(make_pair(1, 0), make_pair(1, 1)));
	while (!q.empty())
	{
		pair<pair<int, int>, pair<int, int> >		pp;
		pp = q.front();
		q.pop();
		for (int i = 0; i < 5; i++)
		{
			int		nextr = pp.second.first + dx[i];
			int		nextc = pp.second.second + dy[i];
			int		brks = 0;
			if (nextr == n && nextc == m)
			{
				cout << pp.first.first + 1;
				return (0);
			}
			if (is_valid(nextr, nextc, pp.first.second, &brks, pp.first.first, i))
			{
				if (brks)
					q.push(make_pair(make_pair(pp.first.first + 1, pp.first.second + 1), make_pair(nextr, nextc)));
				else
					q.push(make_pair(make_pair(pp.first.first + 1, pp.first.second), make_pair(nextr, nextc)));
			}
		}
	}
	cout << -1;
	return (0);
}