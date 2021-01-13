#include <iostream>
#include <queue>

using namespace std;

int				t, m, n, k, ans;
bool			mp[50][50];

void	ft_bfs(int x, int y) {
	queue<pair<int, int> >		q;
	pair<int, int>				pr;
	int							dx[4] = {1, -1, 0, 0};
	int							dy[4] = {0, 0, 1, -1};
	int							nx, ny;

	q.push(make_pair(x, y));
	mp[x][y] = 0;
	while (q.size()) {
		pr = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			x = pr.first; y = pr.second;
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < m && ny < n && mp[nx][ny]) {
				q.push(make_pair(nx, ny));
				mp[nx][ny] = 0;
			}
		}
	}
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		while (k--) {
			int			a, b;
			cin >> a >> b;
			mp[a][b] = 1;
		}
		ans = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (mp[i][j]) {
					ft_bfs(i, j);
					ans++;
				}
			}
		}
		cout << ans;
		if (t) cout << "\n";
	}
	return (0);
}