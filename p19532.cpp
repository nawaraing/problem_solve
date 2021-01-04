#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		a, b, c, d, e, f, i, j;
	cin >> a >> b >> c >> d >> e >> f;
	int		flag = 0;
	for (i = -999 ; i < 1000; i++)
	{
		for (j = -999; j < 1000; j++)
		{
			if ((a * i + b * j == c) && (d * i + e * j == f))
			{
				flag = 1;
				break ;
			}
		}
		if (flag) break ;
	}
	cout << i << " " << j;
	return (0);
}