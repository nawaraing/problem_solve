#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		r, c, n;

	cin >> r; cin >> c; cin >> n;
	if (r % n) r = r / n + 1;
	else r /= n;
	if (c % n) c = c / n + 1;
	else c /= n;
	cout << r * c;
	return (0);
}
