#include <iostream>

using namespace std;

int				dp[5001][5001];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int					n, k;

	cin >> n >> k;
	dp[1][1] = dp[1][0] = 1;
	for (int i = 2; i < n + 1; i++) {
		for (int j = 0; j < k + 1; j++) {
			if (i == 0) dp[i][j] = 1;
			else if (i == j) {
				dp[i][j] = 1;
				break ;
			}
			else {
				if ((dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]) > 10007) dp[i][j] %= 10007;
			}
		}
	}
	cout << dp[n][k];
	return (0);
}