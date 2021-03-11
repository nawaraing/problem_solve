#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int			t, n, m;
char		maps[501][501];
int			visit[501][501];
int			cnt, dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};
queue<pair<int, int> >	q;

int		in_box(int r, int c)
{
	if (r < 0 || r >= n) return 0;
	if (c < 0 || c >= m) return 0;
	return 1;
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		string	arow;
		cnt = 0;
		while (!q.empty()) q.pop();
		for (int i = 0; i < n; i++)
		{
			cin >> arow;
			for (int j = 0; j < m; j++)
			{
				maps[i][j] = arow[j];
				if (maps[i][j] == 'X')
				{
					if (cnt == 0)
					{
						q.push(make_pair(i, j));
						visit[i][j] = 1;
					}
					cnt++;
				}
				visit[i][j] = 0;
			}
		}
		while (!q.empty())
		{
			pair<int, int>	pr = q.front();
			q.pop();
			// visit[pr.first][pr.second] = 1;
			for (int i = 0; i < 4; i++)
			{
				int		nextr = dr[i] + pr.first;
				int		nextc = dc[i] + pr.second;
				if (in_box(nextr, nextc) == 0) continue;
				if (visit[nextr][nextc]) continue ;
				int		flag = 0;
				for (int j = 0; j < 4; j++)
				{
					if (in_box(nextr + dr[j], nextc + dc[j]) == 0) continue;
					if (visit[nextr + dr[j]][nextc + dc[j]])
						flag++;
					if (flag == 2)
						break ;
				}
				if (flag < 2)
				{
					q.push(make_pair(nextr, nextc));
					visit[nextr][nextc] = 1;
					for (int j = 0; j < 4; j++)
					{
						if (visit[nextr + dr[j]][nextc + dc[j]] == 0 && maps[nextr + dr[j]][nextc + dc[j]] == 'X')
						{
							q.push(make_pair(nextr + dr[j], nextc + dc[j]));
							visit[nextr + dr[j]][nextc + dc[j]] = 1;
							cnt--;
						}
					}
				}
				if (cnt == 0) break ;
			}
			// visit[pr.first][pr.second] = 1;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (visit[i][j]) cout << 'X';
				else cout << '.';
			}
			if (t || i != n - 1) cout << "\n";
		}
	}
	return (0);
}
