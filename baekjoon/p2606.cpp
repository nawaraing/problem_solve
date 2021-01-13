#include <iostream>

using namespace std;

bool			virus[101];
bool			connect[101][101];
int				pc, line, ans;

void	ft_dfs(int cur) {
	for (int i = 1; i <= pc; i++) {
		if (connect[cur][i] && !virus[i]) {
			virus[i] = 1;
			ans++;
			ft_dfs(i);
		}
	}
	return ;
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> pc >> line;
	for (int i = 1; i <= line; i++) {
		int a, b;
		cin >> a >> b;
		connect[a][b] = connect[b][a] = 1;
	}
	virus[1] = 1;
	ft_dfs(1);
	cout << ans;
	return (0);
}