#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool				visit[50][50], room[50][50];
int					n, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
priority_queue<vector<int> >	pq;					//   vector < val, x, y >
vector<int>			tmp;
char				c;

vector<int>			ft_make_vector(int val, int x, int y) {
	vector<int>			v;
	v.push_back(val);
	v.push_back(x);
	v.push_back(y);
	return (v);
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			if (c == '1') room[i][j] = 1;
			else room[i][j] = 0;
		}
	}
	pq.push(ft_make_vector(0, 0, 0));
	visit[0][0] = 1;
	while (pq.size()) {
		tmp = pq.top();
		pq.pop();
//		cout << tmp[0] << " " << tmp[1] << " " << tmp[2] << "\n";
		if (tmp[1] == n - 1 && tmp[2] == n - 1) break ;
		for (int i = 0; i < 4; i++) { 
			if (tmp[1] + dx[i] < 0 || tmp[2] + dy[i] < 0 || tmp[1] + dx[i] >= n || tmp[2] + dy[i] >= n || \
				visit[tmp[1] + dx[i]][tmp[2] + dy[i]]) continue ;
			visit[tmp[1] + dx[i]][tmp[2] + dy[i]] = 1;
			if (room[tmp[1] + dx[i]][tmp[2] + dy[i]]) pq.push(ft_make_vector(tmp[0], tmp[1] + dx[i], tmp[2] + dy[i]));
			else pq.push(ft_make_vector(tmp[0] - 1, tmp[1] + dx[i], tmp[2] + dy[i]));
		}
	}
	cout << -tmp[0];
	return (0);
}