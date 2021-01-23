#include <iostream>

using namespace std;

int			n, m;

int		knight(void)
{
	if (n == 1) return (1);
	else if (n == 2)
	{
		if (m < 3) return (1);
		else if (m < 5) return (2);
		else if (m < 7) return (3);
		else return (4);
	}
	else
	{
		if (m == 1) return (1);
		else if (m == 2) return (2);
		else if (m == 3) return (3);
		else if (m >= 4 && m <= 6) return (4);
		else return (m - 2);
	}
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	cout << knight();
	return (0);
}