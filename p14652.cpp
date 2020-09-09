#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		m, k;

	cin >> m; cin >> m; cin >> k;
	cout << k / m << " " << k % m;
	return (0);
}
