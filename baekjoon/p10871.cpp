#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		n, x, a;

	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a < x) cout << a << " ";
	}
	return (0);
}
