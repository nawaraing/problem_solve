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

	unsigned long long			v[30];
	unsigned long long			t, x, n;

	v[0] = 1;
	n = 1;
	for (int i = 1; i < 30; i++) {
		v[i] = v[i - 1] * 2 + (n + 1) * (n + 1);
		n += (n + 1);
	}
	cin >> t;
	while (t--) {
		cin >> n;
		int		ans = 0;
		for (int i = 0; i < 30; i++) {
			if (v[i] > n) break ;
			n -= v[i];
			ans++;
		}
		cout << ans;
		if (t) cout << "\n";
	}
	return (0);
}
