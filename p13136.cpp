#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		r, c, n;

	cin >> r; cin >> c; cin >> n;
	r /= n;
	if (r % n) r++;
	c /= n;
	if (c % n) c++;
	cout << r * c;
	return (0);
}
