#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <list>
//#include <algorithm>
#include <limits.h>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			t, n, a, tmp;
	bool		flag;

	cin >> t;
	while (t--) {
		flag = 0;
		cin >> n;
//		cout << "n : " << n << "\n";
		tmp = INT_MAX;
		for (int i = 0; i < n; i++) {
			cin >> a;
			if (tmp <= a) {
				flag = 1;
			}
			tmp = a;
		}
		if (flag) cout << "YES";
		else cout << "NO";
		if (t) cout << "\n";
	}
	return (0);
}
