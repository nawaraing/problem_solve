#include <iostream>

using namespace std;

int			n, tri[500][500];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cin >> tri[i][j];
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (j == 0) tri[i][j] += tri[i - 1][j];
			else if (j == i) tri[i][j] += tri[i - 1][j - 1];
			else if (tri[i - 1][j] > tri[i - 1][j - 1]) tri[i][j] += tri[i - 1][j];
			else tri[i][j] += tri[i - 1][j - 1];
		}
	}
	int		maxi = 0;
	for (int i = 0; i < n; i++)
	{
		if (maxi < tri[n - 1][i]) maxi = tri[n - 1][i];
	}
	cout << maxi;
	return (0);
}