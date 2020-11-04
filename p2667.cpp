#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int				mp[25][25];
int				cnt;
vector<int>		v;

int		ft_check_houses(int i, int j, int n) {
	queue<pair<int, int> >		q;
	int							ret = 0;

	q.push(make_pair(i, j));
	mp[i][j] = 0;
	ret++;
	while (q.size()) {
		i = q.front().first;
		j = q.front().second;
		q.pop();
		if (i > 0 && mp[i - 1][j]) {
			mp[i - 1][j] = 0;
			ret++;
			q.push(make_pair(i - 1, j));
		}
		if (i < n - 1 && mp[i + 1][j]) {
			mp[i + 1][j] = 0;
			ret++;
			q.push(make_pair(i + 1, j));
		}
		if (j > 0 && mp[i][j - 1]) {
			mp[i][j - 1] = 0;
			ret++;
			q.push(make_pair(i, j - 1));
		}
		if (j < n - 1 && mp[i][j + 1]) {
			mp[i][j + 1] = 0;
			ret++;
			q.push(make_pair(i, j + 1));
		}
	}
	return ret;
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			n;
	char		a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a;
			if (a == '1') mp[i][j] = 1;
			else mp[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mp[i][j]) {
				cnt++;
				v.push_back(ft_check_houses(i, j, n));
			}
		}
	}
	sort(v.begin(), v.end());
	cout << cnt;
	if (cnt) cout << "\n";
	for (int i = 0; i < (int)v.size(); i++) {
		cout << v[i];
		if (i != (int)v.size() - 1) cout << "\n";
	}
	return (0);
}