#include <iostream>

using namespace std;

long long		dp[101][101][101];		// [n, color, cnt];

int		dp_three(int n)
{
	dp[1][1][0] = dp[1][0][1] = dp[1][0][0] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int cnt1 = 0; cnt1 <= i; cnt1++)
		{
			for (int cnt2 = 0; cnt2 <= i - cnt1; cnt2++)
			{
				if (cnt1 > 0)
					dp[i][cnt1][cnt2] = dp[i - 1][cnt1 - 1][cnt2] * (i - cnt1 + 1);
				dp[i][cnt1][cnt2] %= 1000000007;
				if (cnt2 > 0)
					dp[i][cnt1][cnt2] += dp[i - 1][cnt1][cnt2 - 1] * (i - cnt2 + 1);
				dp[i][cnt1][cnt2] %= 1000000007;
				dp[i][cnt1][cnt2] += dp[i - 1][cnt1][cnt2] * (cnt1 + cnt2 + 1);
				dp[i][cnt1][cnt2] %= 1000000007;
			}
		}
	}
	long long ans = 0;
	for (int cnt1 = 0; cnt1 <= n; cnt1++)
	{
		for (int cnt2 = 0; cnt2 <= n - cnt1; cnt2++)
		{
			ans += dp[n][cnt1][cnt2];
			ans %= 1000000007;
		}
	}
	return ans;
}

int		dp_two(int n)
{
	dp[1][0][0] = dp[1][1][1] = 1;
	dp[1][0][1] = dp[1][1][0] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int color = 0; color <= 1; color++)
		{
			for (int cnt = 0; cnt <= i; cnt++)
			{
				dp[i][color][cnt] = dp[i - 1][color][cnt] * (cnt + 1);				//	color X
				dp[i][color][cnt] %= 1000000007;
				if (cnt != 0)
					dp[i][color][cnt] += dp[i - 1][color][cnt - 1] * (i - cnt + 1);			//	color O
				dp[i][color][cnt] %= 1000000007;
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i <= n; i++)
	{
		ans += dp[n][0][i];
		ans %= 1000000007;
	}
	return ans;
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			n, k;
	
	cin >> n >> k;
	if (k == 1)
		cout << 1;
	else if (k == 2)
		cout << dp_two(n);
	else cout << dp_three(n);
	return (0);
}