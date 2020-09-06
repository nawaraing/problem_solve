#include <iostream>

using namespace std;

int		main(void)
{
	int	t, a, b, x, y, n;
	int	one, two;

	cin >> t;
	while (t--) {
		cin >> t;
		cin >> a;
		cin >> b;
		cin >> x;
		cin >> y;
		cin >> n;

		if (a - x + b - y <= n) {
			one = x * y;
			two = one;
		}
		else {
			if (a - x >= n) {
				one = b * (a - n);
			}
			else {
				one = x * (b - n + a - x);
			}
			if (b - y >= n) {
				two = a * (b - n);
			}
			else {
				two = y * (a - n + b - y);
			}
		}
		if (one < two)
			cout << one;
		else cout << two;
		if (t != 0)
			cout << "\n";
	}
	return (0);
}
