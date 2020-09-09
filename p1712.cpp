#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		a, b, c;
	
	cin >> a; cin >> b; cin >> c;
	c -= b;
	if (c <= 0) cout << -1;
	else cout << a / c + 1;
	return (0);
}
