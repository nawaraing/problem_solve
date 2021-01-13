#include <iostream>

using namespace std;

int					sum[100001];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int				n, m, a, b;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		sum[i + 1] = sum[i] + a;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << sum[b] - sum[a - 1];
		if (i != m - 1) cout << "\n";
	}
	return (0);
}