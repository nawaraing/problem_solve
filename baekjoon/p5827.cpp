#include <stdio.h>
#include <utility>
#include <deque>
#include <cstring>

using namespace std;

int		n, m, ans = -1;
char	maps[501][501];
int		visit[501][501][2];
char	c;
pair<int, int>		start, dest;
deque<pair<pair<int, int>, pair<int, bool> > >	d;

pair<int, int>		ft_fall(pair<int, int> user, bool gravity)
{
	if (maps[user.first][user.second] == 'D') return (make_pair(2000, 2000));
	while (1)
	{
		int		under;
		if (!gravity)
		{
			if (user.first == 1) return (make_pair(-1, -1));
			under = user.first - 1;
		}
		else
		{
			if (user.first == n) return (make_pair(-1, -1));
			under = user.first + 1;
		}
		if (maps[under][user.second] == 'D') return (make_pair(1000, 1000));
		if (maps[under][user.second] == '#') return (make_pair(user.first, user.second));
		user.first = under;
	}
	return (make_pair(-1, -1));
}

int		main(void)
{
	scanf("%d %d\n", &n, &m);
	// char	buf[501];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%c", &c);
			maps[i][j] = c;
			if (c == 'C')
				start = make_pair(i, j);
			else if (c == 'D')
				dest = make_pair(i, j);
		}
		if (i != n)
			scanf("%c", &c);
	}
	// //
	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 1; j <= n; j++)
	// 	{
	// 		printf("%c", maps[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// //
	start = ft_fall(start, true);
	if (start.first == -1)
	{
		printf("-1");
		return (0);
	}
	else if (start.first == 1000)
	{
		printf("0");
		return (0);
	}
	visit[start.first][start.second][1] = 1;
	d.push_back(make_pair(make_pair(start.first, start.second), make_pair(0, true)));
	while (!d.empty())
	{
		pair<int, int>		pos = d.front().first;
		int					cnt = d.front().second.first;
		bool				grav = d.front().second.second;
		d.pop_front();
		if (pos.second - 1 > 0 && maps[pos.first][pos.second - 1] != '#')
		{
			pair<int, int>		left = ft_fall(make_pair(pos.first, pos.second - 1), grav);
			if (left.first == 1000 || left.first == 2000) 
			{
				printf("%d", cnt);
				return (0);
			}
			else if (left.first != -1)
			{
				if (visit[left.first][left.second][grav] == 0)
				{
					visit[left.first][left.second][grav] = 1;
					// printf("next is %d %d\n", left.first, left.second);
					d.push_front(make_pair(left, make_pair(cnt, grav)));
				}
			}
		}
		if (pos.second + 1 <= m && maps[pos.first][pos.second + 1] != '#')
		{
			// if (maps[pos.first][pos.second + 1] == 'D')
			// {
			// 	printf("right: %d", cnt);
			// 	return (0);
			// }
			pair<int, int>		right = ft_fall(make_pair(pos.first, pos.second + 1), grav);
			if (right.first == 1000 || right.first == 2000)
			{
				printf("%d", cnt);
				return (0);
			}
			else if (right.first != -1)
			{
				if (visit[right.first][right.second][grav] == 0)
				{
					// printf("next is %d %d\n", right.first, right.second);
					visit[right.first][right.second][grav] = 1;
					d.push_front(make_pair(right, make_pair(cnt, grav)));
				}
			}
		}
		// printf("pos: %d %d\ncnt: %d\n", pos.first, pos.second, cnt);
		pair<int, int>	chng = ft_fall(pos, !grav);
		// printf("chng: %d %d\ncnt: %d\n\n", chng.first, chng.second, cnt);
		if (chng.first == 1000)
		{
			printf("%d", cnt + 1);
			return (0);
		}
		else if (chng.first == 2000)
		{
			printf("%d", cnt);
			return (0);
		}
		else if (chng.first != -1)
		{
			if (visit[chng.first][chng.second][!grav] == 0)
			{
				visit[chng.first][chng.second][!grav] = 1;
				d.push_back(make_pair(chng, make_pair(cnt + 1, !grav)));
			}
		}
	}
	printf("-1");
	return (0);
}