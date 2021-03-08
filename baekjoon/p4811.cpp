#include <stdio.h>

using namespace std;

long long 	dp[62][32]; // day, one pill
int			n;

int		main(void)
{
	while (1)
	{
		scanf("%d", &n);
		if (n == 0) return 0 ;
		scanf("\n");
		dp[1][n] = 1;
		for (int day = 2; day <= 2 * n; day++)
		{
			for (int pill = n; pill >= n - day + 1; pill--)
			{
				if (pill < 0) break ;
				long long h = dp[day - 1][pill];
				if (day % 2 && day / 2 + pill < n)
					h = 0;
				else if (pill == n - day + 1)
					h = 0;
				long long w = dp[day - 1][pill + 1];
				dp[day][pill] = w + h;
			}
		}
		for (int j = 0; j <= n; j++)
		{
			for (int i = 0; i <= 2 * n; i++)
			{
				printf("%lld ", dp[i][j]);
			}
			printf("\n");
		}
		printf("%lld\n", dp[2 * n][0]);
		return 0; //
	}
	return (0);
}