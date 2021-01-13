#include <iostream>

using namespace std;

int			n, m, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}, map[1000][1000];	// visit -1
pair<int, int>		pr;

void	dfs(int row, int col, int l, int r, int	flag)
{
	map[row][col] = -1;
	for (int i = 0; i < 4; i++)
	{
		if (row + dx[i] >= 0 && row + dx[i] < n && col + dy[i] >= 0 && col + dy[i] < m && map[row + dx[i]][col + dy[i]] != 1)
		{
			if (flag == 1 && dx[i] == 1) continue ;
			else if (flag == -1 && dx[i] == -1) continue ;
			// cout << "l : " << l << "  r : " << r << "\n";
			if (dy[i] == 0)
				dfs(row + dx[i], col + dy[i], l, r, flag);
			if (dy[i] == -1 && l > 0)
				dfs(row + dx[i], col + dy[i], l - 1, r, flag);
			if (dy[i] == 1 && r > 0)
				dfs(row + dx[i], col + dy[i], l, r - 1, flag);
		}
	}
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int	l, r;
	char c;
	cin >> n >>m >> l>> r;

	for (int i = 0; i < n; i++)
	{
		for (int j  = 0; j < m; j++)
		{
			cin >> c;
			map[i][j] = c - '0';
			if (map[i][j] == 2)
				pr = make_pair(i, j);
		}
	}
	dfs(pr.first, pr.second, l, r, 1);
	dfs(pr.first, pr.second, l, r, -1);
	int			ans = 0;
	for (int i = 0 ;i < n; i++)
	{
		for (int j = 0; j < m ; j++)
		{
			// cout << map[i][j] << " ";
			if (map[i][j] == -1) ans++;
		}
		// cout << "\n";
	}
	cout << ans;
	return (0);
}