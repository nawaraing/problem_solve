#include <iostream>

using namespace std;

/*
**		브루트포스? dp이네..
**		
**
*/

int			n, width, num[1001];
pair<int, int>		dp[1001][1001];			// [n번째 이름][막줄 이름 갯수]    < ans, 막줄 빈공간 >
int					visit[1001][1001];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> width;
	for (int i = 1; i <= n; i++)
		cin >> num[i];
	dp[1][1] = make_pair(0, width - num[1]);
	visit[1][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		int		minn = 2147483647;
		for (int j = 1; j < i; j++)
		{
			if (visit[i - 1][j] == 0) break ;
			if (minn > dp[i - 1][j].first + dp[i - 1][j].second * dp[i - 1][j].second)
				minn = dp[i - 1][j].first + dp[i - 1][j].second * dp[i - 1][j].second;
		}
		// if (minn == 2147483647)
		// 	minn = 0;
		dp[i][1] = make_pair(minn, width - num[i]);
		visit[i][1] = 1;
		for (int j = 2; j < i + 1; j++)
		{
			if (dp[i - 1][j - 1].second >= num[i] + 1)
			{
				dp[i][j] = make_pair(dp[i - 1][j - 1].first, dp[i - 1][j - 1].second - 1 - num[i]);
				visit[i][j] = 1;
			}
			else
				break ;
		}
	}
	int		minn = 2147483647;
	for (int i = 1; i <= n; i++)
	{
		if (visit[n][i] == 0) break ;
		if (minn > dp[n][i].first)
			minn = dp[n][i].first;
	}
	// if (minn == 2147483647)
	// 	minn = 0;
	// for (int i = 0; i <= n; i++)
	// {
	// 	for (int j = 0; j <= width; j++)
	// 	{
	// 		cout << "["<<dp[i][j].first << ", " << dp[i][j].second << "] ";
	// 	}
	// 	cout << "\n";
	// }
	cout << minn;
	return (0);
}