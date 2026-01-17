#include <iostream>

using namespace std;

int n, k, cnt = 1;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	if (k == 1) {
		cout << "1";
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		if (n % i == 0) {
			cnt++;
			if (cnt == k) {
				cout << i;
				return 0;
			}
		}
	}
	cout << "0";
}
