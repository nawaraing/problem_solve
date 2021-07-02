#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		h, m;

	cin >> h >> m;
	int		total_min = h * 60 + m - 45;
	if (total_min < 0)
		total_min = 1440 + total_min;
	cout << total_min / 60 << " " << total_min % 60;
	return (0);
}