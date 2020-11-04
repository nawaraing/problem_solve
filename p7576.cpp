#include <iostream>
#include <queue>

using namespace std;

int							mp[1001][1001];
queue<pair<int, int> >		q;
int							ans = 1;
int							n, m, a;

void	ft_bfs(void)
{
	pair<int, int>			pr;
	int						dx[4] = {1, -1, 0, 0};
	int						dy[4] = {0, 0, 1, -1};
	int						ny, nx, y, x;

	while (q.size()) {
		pr = q.front();
//		cout << "\npair : < " << pr.first << ", " << pr.second << " >\n";
		q.pop();
		for (int idx = 0; idx < 4; idx++) {
			x = pr.first;
			y = pr.second;
			nx = x + dx[idx];
			ny = y + dy[idx];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !mp[nx][ny]) {
				ans = mp[nx][ny] = mp[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
	return ;
}

int		ft_done(void)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!mp[i][j]) return 0;
	return 1;
}
/*
void	ft_print(void) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << mp[i][j]<< " ";
		}
		cout << "\n";
	}
	return ;
}
*/
int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a;
			mp[i][j] = a;
			if (a == 1) q.push(make_pair(i, j));
		}
	}
	ft_bfs();
//	ft_print();
	if (!ft_done()) ans = 0;
	cout << ans - 1;
	return (0);
}