#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int			rece[32001];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		n, m, a, b;
	vector<int>		v[32001], ans;
	queue<int>		q;

	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		v[a].push_back(b);
		rece[b]++;
	}
	for (int i = 1; i <= n; i++) {
		if (!rece[i]) q.push(i);
	}
	while (q.size()) {
		a = q.front();
		q.pop();
		ans.push_back(a);
		for (int i = 0; i < v[a].size(); i++) {
			if (rece[v[a][i]] && !(--rece[v[a][i]])) q.push(v[a][i]);
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		if (i) cout << " ";
		cout << ans[i];
	}
	return (0);
}