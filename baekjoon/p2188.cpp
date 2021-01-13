#include <iostream>
#include <vector>

using namespace std;

int					n, m, s, a, cnt = 0;
bool				check[201];
int					use[201];
vector<int>			graph[201];

bool	ft_dfs(int idx) {
	for (int i = 0; i < graph[idx].size(); i++) {
		int a = graph[idx][i];
		if (check[a]) continue ;
		check[a] = true;
		if (use[a] == 0 || ft_dfs(use[a])) {
//			cout << "a : " << a << "  idx : " << idx << "\n";
			use[a] = idx;
			return (true);
		}
	}
	return (false);
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		while (s--) {
			cin >> a;
			graph[i].push_back(a);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) check[j] = false;
		if (ft_dfs(i)) cnt++;
//		for (int j = 0; j < m; j++) cout << use[j + 1] << " ";
//		cout << "\n";
	}
	cout << cnt;
	return (0);
}