#include <iostream>

using namespace std;

double		dp[101][101][101][3];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		t, r, y, b;
	double	num;
	
	num = 1;
	num /= 3;
	for (int i = 1; i <= 100; i++)
	{
		for (int j = 0; j < 3; j++)
			dp[i][i][i][j] = num;
		dp[i][0][0][0] = dp[0][i][0][1] = dp[0][0][i][2] = 1;
		for (int j = 1; j <= 100; j++)
			dp[i][j][0][0] = dp[i][0][j][2] = dp[0][i][j][1] = 1;
	}
	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			for (int k = 1; k <= 100; k++)
			{
				double	ry = (i * j);
				double	yb = (j * k);
				double	br = (k * i);
				double	sum = ry + yb + br;
				ry /= sum;
				yb /= sum;
				br /= sum;
				double		rwin = ry * dp[i][j - 1][k][0] + yb * dp[i][j][k - 1][0] + br * dp[i - 1][j][k][0];
				double		ywin = ry * dp[i][j - 1][k][1] + yb * dp[i][j][k - 1][1] + br * dp[i - 1][j][k][1];
				double		bwin = ry * dp[i][j - 1][k][2] + yb * dp[i][j][k - 1][2] + br * dp[i - 1][j][k][2];
				dp[i][j][k][0] = rwin;
				dp[i][j][k][1] = ywin;
				dp[i][j][k][2] = bwin;
			}
		}
	}
	cin >> t;
	while (t--)
	{
		cin >> r >> y >> b;
		for (int i = 0;i < 3; i++)
		{
			printf("%.10f", dp[r][y][b][i]);
			if (i != 2) cout << " ";
		}
		if (t) cout << "\n";
	}


	return (0);
}