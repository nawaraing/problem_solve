#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int	n, a, minn = 0;

	cin >> n;
	while (n--)
	{
		cin >> a;
		if (a > minn)
			minn = a;
	}
	cout << minn;
	return (0);
}