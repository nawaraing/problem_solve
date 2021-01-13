#include <iostream>
#include <cmath>

using namespace std;

int			n, m, ans = 0;
char		c;
int			dp[1000][1000];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			cin >> c;
			dp[i][j] = c - '0';
			if (dp[i][j]) ans = 1;
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++) {
			if (dp[i - 1][j] == 0 || dp[i][j - 1] == 0 || dp[i - 1][j - 1] == 0 || dp[i][j] == 0) continue ;
			int		minn = min(dp[i - 1][j], dp[i][j - 1]);
			minn = min(minn, dp[i - 1][j - 1]);
			dp[i][j] = minn + 1;
			if (ans < dp[i][j]) ans = dp[i][j];
		}
	}
	cout << pow(ans, 2);
	return (0);
}