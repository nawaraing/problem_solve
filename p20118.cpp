#include <iostream>

using namespace std;

int			n, m;
int			maps[1000][1000];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i =0  ; i < n; i++)
	{
		for (int j  =0 ; j < m; j++)
			cin >> maps[i][j];
	}

	if (n + m % 2) cout << 2 * (n + m - 1);
	else cout << 2 * (n + m);

	int		r = 0, c = 0;
	while (c <= m - 2)
	{
		cout << 0 << " " << c << "\n";
		cout << 0 << " " << c + 2 << "\n";
		cout << 0 << " " << c << "\n";
		cout << 0 << " " << c + 2 << "\n";
		c += 2;
	}
	if (m % 2 && (m + n) % 2)
	{
		r = 0;
		c = m - 1;
	}
	else if (m % 2 && (m + n) % 2 == 0)
	{
		cout << 0 << " " << m - 1;
		cout << 1 << " " << m - 1;
		cout << 0 << " " << m - 1;
		cout << 1 << " " << m - 1;
		
	}
	return (0);
}