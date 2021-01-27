#include <iostream>
#include <queue>

using namespace std;
int		visit[1001][1001], maps[1001][1001], sett[1001][1001], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int		n, m;


void	bfs(int r, int c)
{
	queue<pair<int, int> >		q;
	int		cnt = 0;
	q.push(make_pair(r, c));
	while (q.empty())
	{
		cnt++;
		pair<int, int>		pr = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			nextr = q.first + dx[i];
			nextc = q.second + dy[i];
			if (visit[nextr][nextc]) continue ;
			visit[nextr][nextc] = 1;
		}
	}
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
			char	c;
			cin >> c;
			if (c == '1') maps[i][j] = 1;
			else maps[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (maps[i][j] == 0 && sett[i][j] == 0)
			{
				bfs(i, j);
			}
		}
	}
	return (0);
}