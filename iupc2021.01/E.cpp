#include <iostream>

using namespace std;

long long			n;
pair<long long, long long>		dp[1001][5];	// [ 땅, 1, 2, 연1, 연2 ]


int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	dp[1][0].first = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i][0].first = dp[i - 1][0].first + dp[i - 1][1].first + dp[i - 1][3].first;
		dp[i][1].first = dp[i - 1][0].first;
		dp[i][3].first = dp[i - 1][1].first;
		dp[i][0].second = dp[i - 1][0].second + dp[i - 1][1].second + dp[i - 1][2].second + dp[i - 1][3].second + dp[i - 1][4].second;
		dp[i][1].second = dp[i - 1][0].second;
		dp[i][2].second = dp[i - 1][0].first + dp[i - 1][0].second;
		dp[i][3].second = dp[i - 1][1].second + dp[i - 1][2].second;
		dp[i][4].second = dp[i - 1][1].first + dp[i - 1][1].second;
		for (int j = 0; j < 5; j++)
		{
			dp[i][j].first %= 1000000007;
			dp[i][j].second %= 1000000007;
		}
	}
	cout << (dp[n][0].second + dp[n][1].second + dp[n][2].second + dp[n][3].second + dp[n][4].second) % 1000000007;
	return (0);
}