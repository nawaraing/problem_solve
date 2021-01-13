#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		h, m, s, t;

	cin >> h; cin >> m; cin >> s; cin >> t;
	s += m * 60 + h * 3600 + t;
	s %= 86400;
	cout << s / 3600 << " ";
	s %= 3600;
	cout << s / 60 << " ";
	s %= 60;
	cout << s;
	return (0);
}
