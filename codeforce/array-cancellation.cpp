#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long		t, n, sum, a;

	cin >> t;
	while (t--) {
		cin >> n;
		sum = 0;
		for (long long i = 0; i < n; i++) {
			cin >> a;
			sum += a;
			if (sum < 0) sum = 0;
		}
		cout << sum;
		if (t != 0) cout << "\n";
	}
	return (0);
}
