#include <iostream>
#include <queue>

using namespace std;

int		visit[200][200];
int		r1, c1, r2, c2;
int		n;
int		dx[6] = {-2, -2, 0, 0, 2, 2}, dy[6] = {-1, 1, -2, 2, -1, 1};
queue<pair<int, pair<int, int> > >	q; //	cnt r c

int		is_valid(int r, int c)
{
	if (r < 0 || c < 0) return (0);
	if (r >= n || c >= n) return (0);
	if (visit[r][c]) return (0);
	return (1);
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> r1 >> c1 >> r2 >> c2;
	q.push(make_pair(0, make_pair(r1, c1)));
	while (!q.empty())
	{
		pair<int, pair<int, int> >		ppr = q.front();
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int		nextr = ppr.second.first + dx[i];
			int		nextc = ppr.second.second + dy[i];
			if (nextr == r2 && nextc == c2)
			{
				cout <<ppr.first + 1;
				return (0);
			}
			else if (is_valid(nextr, nextc))
			{
				visit[nextr][nextc] = 1;
				q.push(make_pair(ppr.first + 1, make_pair(nextr, nextc)));
			}
		}
	}
	cout << -1;
	return (0);
}