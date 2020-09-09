#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		a, b, c, d, e;

	cin >> a; cin >> b; cin >> c; cin >> d; cin >> e;
	if (a > 0) cout << (b - a) * e;
	else if (a == 0) cout << d + b * e;
	else {
		a =  a * -1 * c;
		a += d;
		a += b * e;
		cout << a;
	}
	return (0);
}
