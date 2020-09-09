#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int	a, b, c, d;

	cin >> a; cin >> b; cin >> c; cin >> d;
	a += d;
	b += c;
	if (a > b) cout << a - b;
	else cout << b - a;
	return (0);
}
