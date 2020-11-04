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

	int				t, n, x, a, sums;
	int				flag;

	cin >> t;
	while (t--) {
		flag = 0;
		sums = 0;
		cin >> n >> x;
		for (int i = 0; i < n; i++) {
			cin >> a;
			if (a == x) flag++;
			sums += a;
		}
		if (flag == n) cout << 0;
		else if (flag > 0 || ((sums % n == 0) && (sums / n == x))) cout << 1;
		else cout << 2;
		if (t) cout << "\n"; 
	}

	return (0);
}
