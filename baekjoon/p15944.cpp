#include <stdio.h>
#include <deque>

using namespace std;

int				n, m, d, dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};
char			c, maps[501][501];
int				visit[501][501];
deque<pair<pair<int, int>, int> >	dq;

int		main(void)
{
	scanf("%d %d %d\n", &n, &m, &d);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%c", &c);
			maps[i][j] = c;
		}
		if (i != n - 1)
			scanf("%c", &c);
	}
	dq.push_front(make_pair(make_pair(0, 0), 0));
	visit[0][0] = 1;
	while (!dq.empty())
	{
		pair<int, int>	pos = dq.front().first;
		int				cnt = dq.front().second;
		dq.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int		nextr = pos.first + dr[i];
			int		nextc = pos.second + dc[i];
			if (nextr < 0 || nextr >= n) continue ;
			if (nextc < 0 || nextc >= m) continue ;
			if (nextr == n - 1 && nextc == m - 1) {
				printf("%d", cnt);
				return (0);
			}
			if (maps[nextr][nextc] == '.')
			{
				if (visit[nextr][nextc]) continue ;
				visit[nextr][nextc] = 1;
				dq.push_front(make_pair(make_pair(nextr, nextc), cnt));
			}
		}
		for (int j = -d; j <= d; j++)
		{
			for (int k = -d; k <= d; k++)
			{
				if (pos.first + j < 0 || pos.first + j >= n) continue ;
				if (pos.second + k < 0 || pos.second + k >= m) continue ;
				if (maps[pos.first + j][pos.second + k] == '#')
				{
					if (visit[pos.first + j][pos.second + k]) continue ;
					visit[pos.first + j][pos.second + k] = 1;
					dq.push_back(make_pair(make_pair(pos.first + j, pos.second + k), cnt + 1));
				}
			}
		}
	}
	return (0);
}