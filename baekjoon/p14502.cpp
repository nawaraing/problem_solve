#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int		n, m, ret = 0;

struct	s_lab {
	int						lab[9][9];
	queue<pair<int, int> >	q;
};

void	ft_bfs(s_lab lab) {
	int					dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
	pair<int, int>		p;
	int					cnt = 0;

	while (lab.q.size()) {
		p = lab.q.front();
		lab.q.pop();
		for (int i = 0; i < 4; i++) {
			if (p.first + dx[i] > 0 && p.first + dx[i] <= n &&\
					p.second + dy[i] > 0 && p.second + dy[i] <= m &&\
					lab.lab[p.first + dx[i]][p.second + dy[i]] == 0) {
				lab.q.push(make_pair(p.first + dx[i], p.second + dy[i]));
				lab.lab[p.first + dx[i]][p.second + dy[i]] = 2;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (lab.lab[i][j] == 0) cnt++;
	if (cnt > ret) ret = cnt;
}

int		ft_backtracking(s_lab *lab,int i, int j, int cnt) {
	if (cnt == 3)
		return (1);

	while (i <= n) {
		while (j <= m) {
			if (lab->lab[i][j] == 0) {
				lab->lab[i][j] = 1;
				if (1 == ft_backtracking(lab, i, j, cnt + 1))
					ft_bfs(*lab);
				lab->lab[i][j] = 0;
			}
			j++;
		}
		i++;
		j = 1;
	}
	return (0);
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	s_lab			lab;
	int				a, cnt = 0;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) { 
		for (int j = 1; j <= m; j++) {
			cin >> a;
			lab.lab[i][j] = a;
			if (a == 2) lab.q.push(make_pair(i, j));
		}
	}
	ft_backtracking(&lab, 1, 1, cnt);
	cout << ret;
	return (0);
}