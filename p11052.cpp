#include <iostream>

using namespace std;

int					dp[1001];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			n, a;
	
	cin >> n;
	for (int i = 0 ; i < n; i++) {
		cin >> a;
		for (int j = 0; j < i; j++) {
			dp[i - j] + dp[j];
		}
	}
	return (0);
}