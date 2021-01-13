#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int			box[100][100][100];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int					m, n, h, a, cnt = 0, ret;
	queue<vector<int> >	q;
	vector<int>			wall;
	int					dm[6] = {1, -1, 0, 0, 0, 0};
	int					dn[6] = {0, 0, 1, -1, 0, 0};
	int					dh[6] = {0, 0, 0, 0, 1, -1};
	vector<int>			v;

	cin >> m >> n >> h;
	for (int k = 0; k < h; k++) {
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < m; i++) {
				cin >> a;
				box[i][j][k] = a;
				if (a == 1) {
					v.clear();
					v.push_back(i);
					v.push_back(j);
					v.push_back(k);
					q.push(v);
				}
			}
		}
	}
	wall.push_back(-1);
	q.push(wall);
	while (q.size() > 1) {
		vector<int> tmp;
		v = q.front();
		q.pop();
		if (v[0] == -1) {
			cnt++;
			if (q.size()) {
				q.push(wall);
				continue ;
			}
			else
				break ;
		}
		for (int i = 0; i < 6; i++) {
			int			flag = 0;
			tmp.clear();
			tmp.push_back(v[0] + dm[i]);
			tmp.push_back(v[1] + dn[i]);
			tmp.push_back(v[2] + dh[i]);
			for (int j = 0; j < 3; j++)
				if (tmp[j] < 0) flag = 1;
			if (tmp[0] >= m || tmp[1] >= n || tmp[2] >= h) flag = 1;
			if (flag == 1) continue ;
			if (box[v[0] + dm[i]][v[1] + dn[i]][v[2] + dh[i]] == 0) {
				box[v[0] + dm[i]][v[1] + dn[i]][v[2] + dh[i]] = 1;
				q.push(tmp);
			}
		}
	}
	ret = cnt;
	for (int k = 0; k < h; k++) {
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < m; i++) {
				if (box[i][j][k] == 0) {
					ret = -1;
					break ;
				}
			}
			if (ret == -1)
				break ;
		}
		if (ret == -1)
			break ;
	}
	cout << ret;
	return (0);
}