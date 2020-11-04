#include <iostream>
#include <queue>

using namespace std;

int			mp[100][100];
queue<pair<int, int> >	q;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int				n, m;
	char			c;
	pair<int, int>	p;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {				// map save
		for (int j = 0; j < m; j++) {
			cin >> c;
			if (c == '1') mp[i][j] = 1;
		}
	}
	mp[0][0] = 0;
	q.push(make_pair(0, 0));
	while (q.size()) {
		p = q.front();
		q.pop();
		if (p.first > 0 && mp[p.first - 1][p.second] == 1) {
			q.push(make_pair(p.first - 1, p.second));
			mp[p.first - 1][p.second] = mp[p.first][p.second] + 1;
		}
		if (p.first < n - 1 && mp[p.first + 1][p.second] == 1) {
			q.push(make_pair(p.first + 1, p.second));
			mp[p.first + 1][p.second] = mp[p.first][p.second] + 1;
		}
		if (p.second > 0 && mp[p.first][p.second - 1] == 1) {
			q.push(make_pair(p.first, p.second - 1));
			mp[p.first][p.second - 1] = mp[p.first][p.second] + 1;
		}
		if (p.second < m - 1 && mp[p.first][p.second + 1] == 1) {
			q.push(make_pair(p.first, p.second + 1));
			mp[p.first][p.second + 1] = mp[p.first][p.second] + 1;
		}
		if (p.first == n - 1 && p.second == m - 1) break ;
	}
	cout << mp[n - 1][m - 1] + 1;
	return (0);
}