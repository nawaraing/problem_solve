#include <iostream>

using namespace std;

int			t, k, arr[501], sum[501];
int			dp[501][501];

void			split_arr(int start, int end)
{
	int		summation = sum[end] - sum[start - 1];
	int		cost = 2147483647;

	if (dp[start][end]) return ;
	if (start == end) return ;
	for (int i = start; i < end; i++)
	{
		split_arr(start, i);
		split_arr(i + 1, end);
		if (cost > dp[start][i] + dp[i + 1][end])
			cost = dp[start][i] + dp[i + 1][end];
	}
	dp[start][end] = summation + cost;
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--)
	{
		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j <= k; j++)
				dp[i][j] = 0;
		}
		cin >> k;
		for (int i = 1; i <= k; i++)
		{
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}
		split_arr(1, k);
		cout << dp[1][k];
		if (t) cout << "\n";
	}
	return (0);
}