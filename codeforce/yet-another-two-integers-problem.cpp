#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int	a, b, t, tmp;

	cin >> t;
	while (t--) {
		cin >> a;
		cin >> b;
		if (b > a) {
			tmp = a;
			a = b;
			b = tmp;
		}
		a -= b;
		if (a % 10 != 0)
			cout << a / 10 + 1;
		else
			cout << a / 10;
		if (t != 0) cout << "\n";
	}
	return (0);
}
