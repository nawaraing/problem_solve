#include <iostream>
#include <queue>

using namespace std;

int					dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int					n, m, ret = 0;

class c_map {
	public:
		char			map[300][300];
};
/*
int		ft_is_crush(c_map map) {
	int			cnt = 0;
	queue<pair<int, int> >	q;
	pair<int, int>			pr;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map.map[i][j] == 0) continue ;
			if (++cnt > 1) break ;
			q.push(make_pair(i, j));
			while (q.size()) {
				pr = q.front();
				q.pop();
				map.map[pr.first][pr.second] = 0;
				for (int k = 0; k < 4; k++) {
					if (map.map[pr.first + dx[k]][pr.second + dy[k]]) q.push(make_pair(pr.first + dx[k], pr.second + dy[k]));
				}
			}
		}
	}
	return (cnt);
}
*/
int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	c_map				map, temp;
	int					cnt = 0;
	char				island = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++) {
			cin >> cnt;
			map.map[i][j] = (int)cnt;
		}
	}
	cnt = 0;
	temp = map;
	while (1) {
		cnt++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map.map[i][j]) {
					for (int k = 0; k < 4; k++) {
						if (temp.map[i + dx[k]][j + dy[k]] == 0 && map.map[i][j] > 0) {
							map.map[i][j]--;
						}
					}
				}
//				cout << map.map[i][j] << " ";
			}
//			cout << "\n";
		}
//		cout << "\n";
/////////////////////////
		temp = map;
		queue<pair<int, int> >	q;
		pair<int, int>			pr;
		bool					flag = 0;
		island = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (temp.map[i][j] == 0) continue ;
//				cout << "island : " << island << "\n";
				if (++island > 1) {
					flag = 1;
					break ;
				}
				while (q.size()) q.pop();
//				cout << "i : " << i << " j : " << j << "\n";
				q.push(make_pair(i, j));
				while (q.size()) {
					pr = q.front();
					q.pop();
					temp.map[pr.first][pr.second] = 0;
					for (int k = 0; k < 4; k++) {
						if (temp.map[pr.first + dx[k]][pr.second + dy[k]]) {
							q.push(make_pair(pr.first + dx[k], pr.second + dy[k]));
//							cout << "q.push : " << q.back().first << " " << q.back().second << "\n";
						}
					}
				}
			}
			if (flag) break ;
		}
		if (island == 0 || island == 2) break ;
		temp = map;
/////////////////////////////
	}
	if (island == 0) cout << 0;
	else cout << cnt;
	return (0);
}