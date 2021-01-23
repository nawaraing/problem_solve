#include <iostream>
#include <limits.h>

using namespace std;

int			city[101][101], n, m;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n ; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) city[i][j] =0 ;
			else city[i][j] = INT_MAX;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int	a, b, c;
		cin >> a>> b>> c;
		if (city[a][b] == INT_MAX)
			city[a][b] = c;
		else if (city[a][b] > c)
			city[a][b] = c;
	}
	for (int check = 1; check <= n; check++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (check == i) continue ;
			for (int j = 1; j<= n; j++)
			{
				if (check == j) continue ;
				if (i == j) {
					continue ;
				}
				if (city[i][check] == INT_MAX || city[check][j] == INT_MAX) continue ;
				if (city[i][j] > city[i][check] + city[check][j])
					city[i][j] = city[i][check] + city[check][j];
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n ;j++)
		{
			if (city[i][j] == INT_MAX) cout << 0;
			else cout << city[i][j];
			cout << " ";
		}
		cout << "\n";
	}
	return (0);
}