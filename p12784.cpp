#include <iostream>

using namespace std;

int			t, n, m, a, b, c;
int			graph[1001][1001];
bool		used[1001];

int			ft_dfs(int node, int cost) {
	int			ret = 0;

	for (int i = 1; i <= n; i++) {
		if (graph[node][i] == 0 || used[i]) continue ;
		used[i] = true;
		ret += ft_dfs(i, graph[node][i]);
	}
//	cout << "node : " << node << "  cost : " << cost << "  ret : " << ret << "\n";
	if (ret == 0) return (cost);
	if (ret < cost) return (ret);
	else return (cost);
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			res;

	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) graph[i][j] = 0;
			used[i] = 0;
		}
		while (m--) {
			cin >> a >> b >> c;
			graph[a][b] = graph[b][a] = c;
		}
		used[1] = true;
		if ((res = ft_dfs(1, 2147483647)) == 2147483647) cout << 0 << "\n";
		else cout << res << "\n";
	}
	return (0);
}