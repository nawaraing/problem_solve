#include <iostream>
#include <queue>

using namespace std;

int			dp[5000];
queue<int>	q;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			n, a;

	cin >> n;
	dp[3] = 1; dp[5] = 1;
	q.push(5); q.push(3);
	while (q.size()) {
		a = q.front();
		q.pop();
		if (a + 3 <= n && (!dp[a + 3] || dp[a] + 1 < dp[a + 3])) {
			dp[a + 3] = dp[a] + 1;
			q.push(a + 3);
		}
		if (a + 5 <= n && (!dp[a + 5] || dp[a] + 1 < dp[a + 5])) {
			dp[a + 5] = dp[a] + 1;
			q.push(a + 5);
		}
	}
	if (dp[n]) cout << dp[n];
	else cout << -1;
	return (0);
}