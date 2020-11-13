#include <iostream>

using namespace std;

bool			map[101][101];//, visit[101][101];
int				n, m, k, r, c, ret, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int					ft_dfs(int i, int j, int cnt) {
	map[i][j] = 0;
	for (int k = 0; k < 4; k++) {
		if (i + dx[k] >= 1 && i + dx[k] <= n && j + dy[k] >= 1 && j + dy[k] <= m &&
			map[i + dx[k]][j + dy[k]] == 1)
			cnt = ft_dfs(i + dx[k], j + dy[k], cnt + 1);
	}
	if (cnt > ret) ret = cnt;
	return (cnt);
}

int					main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	while (k--) {
		cin >> r >> c;
		map[r][c] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j])
				ft_dfs(i, j, 1);
		}
	}
	cout << ret;
}