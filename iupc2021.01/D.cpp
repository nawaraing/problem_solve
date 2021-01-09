#include <iostream>

using namespace std;

long long			maps[2001][2001];
long long			ans[2001][2001];
long long			n, m, a;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n ;i++)
	{
		for (int j = 0; j < n ;j++)
		{
			cin >> maps[i][j];
		}
	}
	for (int i = 0; i < n - m + 1 ;i++)
	{
		for (int j = 0; j < n - m + 1 ;j++)
		{
			a = -maps[i][j];
			for (int dr = 0; dr < m; dr++)
			{
				for (int dc = 0; dc < m; dc++)
				{
					maps[i + dr][j + dc] += a;
					if (dr == m / 2 && dc == m / 2) ans[i + dr][j + dc] = a;
				}
			}
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << ans[i][j];
			if (j != n - 1) cout << " ";
		}
		if (i != n - 1) cout << "\n";
	}
	return (0);
}