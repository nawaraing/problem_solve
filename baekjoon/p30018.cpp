#include <iostream>

using namespace std;

int n, ans = 0;
int a[101], b[101];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	for (int i = 0; i < n; i++) {
		if (a[i] > b[i]) {
			ans += a[i] - b[i];
		}
	}
	cout << ans;
}