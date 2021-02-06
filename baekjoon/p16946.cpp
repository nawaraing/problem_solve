#include <iostream>
#include <queue>

using namespace std;

int		n, m;
int		maps[1001][1001], visit[1001][1001];
int		aria[1000000];
int		spot = 1, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int		in_maps(int r, int c)
{
	if (r < 0 || r >= n) return (0);
	if (c < 0 || c >= m) return (0);
	return (1);
}

void	ft_bfs(int r, int c)
{
	// cout << "in bfs  r : " << r << "  c : " << c << "\n";
	queue<pair<int, int> >		q;
	pair<int, int>				pr;
	int							cnt = 1;
	q.push(make_pair(r, c));
	visit[r][c] = spot;
	while (!q.empty())
	{
		pr = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextr = pr.first + dx[i];
			int nextc = pr.second + dy[i];
			if (in_maps(nextr, nextc) == 0) continue ;
			if (maps[nextr][nextc] == 1 || visit[nextr][nextc] > 0) continue ;
			visit[nextr][nextc] = spot;
			cnt++;
			q.push(make_pair(nextr, nextc));
		}
	}
	// cout << "spot : " << spot << "  cnt : " << cnt << "\n";
	aria[spot++] = cnt;
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
			char c;
			cin >> c;
			if (c == '0') maps[i][j] = 0;
			else maps[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (maps[i][j] == 0 && visit[i][j] == 0)
				ft_bfs(i, j);
		}
	}
	// cout << "=== ans ===\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (maps[i][j] == 0) cout << 0;
			else
			{
				int		num = 0;
				for (int k = 0; k < 4; k++)
				{
					int		tmp;
					if (in_maps(i + dx[k], j + dy[k]) == 0) continue ;
					int		flag = 0;
					for (int l = 0; l < k; l++)
					{
						if (visit[i + dx[k]][j + dy[k]] == visit[i + dx[l]][j + dy[l]])
						{
							flag = 1;
							break ;
						}
					}
					if (flag == 0)
						num += aria[visit[i + dx[k]][j + dy[k]]];
				}
				cout << (num + 1) % 10;
			}
			// cout << " ";
		}
		cout << "\n";
	}
	return (0);
}