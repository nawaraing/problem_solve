#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long 			n, m, t, a;

	cin >> t;
	while (t--)
	{
		cin >> n >> m >> a;
		long long div = a / n;
		long long mod = a % n;
		if (mod == 0)
			cout << m * (n - 1) + div;
		else
			cout << m * (mod - 1) + div + 1;
		if (t) cout << endl;
	}

	return (0);
}
