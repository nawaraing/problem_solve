#include <iostream>
#include <cmath>

using namespace std;

int				n, p;
char			c;
int				dp[1 << 16];
int				graph[16][16];

int				ft_dfs(int num, int stat) {
	if (num == p) return (0);
	if (dp[stat] != -1) return (dp[stat]);

	dp[stat] = 2147483647;
	for (int from = 0; from < n; from++) {
		if (stat & (1 << from)) {
			for (int to = 0; to < n; to++) {
				if (stat & (1 << to) || from == to) continue ;
				dp[stat] = min(dp[stat], ft_dfs(num + 1, stat | (1 << to)) + graph[from][to]);
			}
		}
	}
	return (dp[stat]);
}

int				main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	int		cur = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> c;
		if (c == 'Y') {
			cur |= (1 << i);
			cnt++;
		}
	}
	cin >> p;
	for (int i = 0; i < (1 << 16); i++) dp[i] = -1;
	if (cnt >= p) cout << 000;
	else if (cnt == 0) cout << -1;
	else cout << ft_dfs(cnt, cur);
	return (0);
}