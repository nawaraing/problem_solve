#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long		t, n, a, q, pre, ret;
	bool			flag;

	cin >> t;
	while (t--) {
		pre = -1;
		ret = 0;
		cin >> n >> q;
		flag = 0;		// 0 is up
		for (long long i = 0; i < n; i++) {
			cin >> a;
			if (!flag) {
				if (pre > a) {
					ret += pre;
					flag = 1;
				}
			}
			else {
				if (pre < a) {
					ret -= pre;
					flag = 0;
				}
			}
//			cout << "pre : " << pre << "   a : " << a << "   ret : " << ret << "\n";
			pre = a;
		}
		if (!flag) ret += pre;
		cout << ret;
		if (t) cout << "\n";
	}
	return (0);
}
