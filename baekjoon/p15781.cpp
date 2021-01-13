#include <iostream>

using namespace std;

int		n, m, a, ans = 0, maxi;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	while (n--)
	{
		cin >> a;
		if (maxi < a)
			maxi = a;
	}
	ans+= maxi;
	maxi = 0;
	while (m--)
	{
		cin >> a;
		if (maxi < a)
			maxi = a;
	}
	ans+= maxi;
	cout << ans;
	return (0);
}