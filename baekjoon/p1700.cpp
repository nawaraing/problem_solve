#include <iostream>

using namespace std;

bool		use[101], want[101], keep[101];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			n, k, cnt = 0, ret = 0, i = 0, a;

	cin >> n >> k;
	i--;
	while (++i < k) {						//	use setting
		if (cnt == n) break ;
		cin >> a;
		if (!use[a]) {
			use[a] = 1;
			cnt++;
		}
	}
	cnt = 0;
	i--;
	while (++i < k) {
		cin >> a;
		if (keep[a] || want[a] || (use[a] && cnt == 0))
			continue ;
		else if (use[a]) {
			keep[a] = 1;
			cnt++;
		}
		else {
			want[a] = 1;
			cnt++;
		}
		if (cnt == n || i == k - 1) {
			for (int j = 1; j <= k; j++) {
				if (use[j] && !keep[j])
					use[j] = 0;
				else if (want[j]) {
					use[j] = 1;
					ret++;
					want[j] = 0;
				}
				else if (keep[j]) keep[j] = 0;
			}
			cnt = 0;
		}
	}
	cout << ret;
	return (0);
}