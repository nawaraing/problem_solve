#include <iostream>

using namespace std;

long long			n, dp[91];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= n; i++)
	{
		dp[i] += 1;
		for (int j = 1; j < i - 1; j++)
		{
			dp[i] += dp[j];
		}
	}
	cout << dp[n];
	return (0);
}