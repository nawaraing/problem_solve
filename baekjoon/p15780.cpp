#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			n, k, a, can = 0;

	cin >> n >> k;
	while (k--)
	{
		cin >> a;
		if (a % 2)
			can += a / 2 + 1;
		else can += a / 2;
	}
	if (can >= n) cout << "YES";
	else cout << "NO";
	return (0);
}