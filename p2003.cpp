#include <iostream>
#include <queue>

using namespace std;

int			sum[10001];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			a, b, n, m, cnt = 0;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		sum[i] = sum[i - 1] + a;
	}
	a = 0; b = 1;
	while (1) {
		if (sum[b] - sum[a] > m) a++;
		else if (sum[b] - sum[a] < m) b++;
		else {
			cnt++;
			a++;
		}
		if (a > 10000 || b > 10001) break ;
	}
	cout << cnt;
	return (0);
}