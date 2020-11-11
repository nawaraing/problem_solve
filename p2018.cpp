#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int					n, a, b, cnt = 0, sum;

	cin >> n;
	a = 1; b = 2; sum = 1;
	while (1) {
		if (sum > n) {
			sum -= a; a++;
		}
		else if (sum < n) {
			sum += b; b++;
		}
		else {
			cnt++;
			sum -= a; a++;
		}
		if (a > n || b > n + 1) break ;
	}
	cout << cnt;
	return (0);
}