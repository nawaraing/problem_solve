#include <iostream>

using namespace std;

int			n, dp[1000];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		if (dp[i] > 10007) dp[i] %= 10007;
	}
	cout << dp[n];
	return (0);
}