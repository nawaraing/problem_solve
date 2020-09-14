#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <list>
//#include <algorithm>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	unsigned long long			t, x, y, k, n;

	cin >> t;
	while (t--) {
		cin >> x; cin >> y; cin >> k;
		n = 0;
		if (((y + 1) * k - 1) % (x - 1))
			n = ((y + 1) * k - 1) / (x - 1) + 1;
		else
			n = ((y + 1) * k - 1) / (x - 1);
		cout << n + k;
		if (t != 0) cout << "\n";
	}
	return (0);
}
