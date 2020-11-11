#include <iostream>
#include <queue>

using namespace std;

int				w, h, map[50][50], cnt;
pair<int, int>				pr;

void	ft_bfs() {
	queue<pair<int, int> >		q;
	int			dx[8] = {1, -1, 0, 0, 1, -1, 1, -1}, dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (1 == map[i][j]) {
				cnt++;
				map[i][j] = 0;
				q.push(make_pair(i, j));
			}
			while (q.size()) {
				pr = q.front();
				q.pop();
				for (int k = 0; k < 8 ; k++) {
					if (pr.first + dx[k] >= 0 && pr.first + dx[k] < h \
					&& pr.second + dy[k] >= 0 && pr.second + dy[k] < w && map[pr.first + dx[k]][pr.second + dy[k]])
					{
						map[pr.first + dx[k]][pr.second + dy[k]] = 0;
						q.push(make_pair(pr.first + dx[k], pr.second + dy[k]));
					}
				}
			}
		}
	}
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	cin >> w >> h;
	if (w == 0 && h == 0) return (0);
	while (1) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		cnt = 0;
		ft_bfs();
		cout << cnt;
		cin >> w >> h;
		if (w == 0 && h == 0) break ;
		else cout << "\n";
	}
	return (0);
}