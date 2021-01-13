#include <iostream>
#include <queue>

using namespace std;

int			n, m;
queue<int>	dp;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	if (n < m)
	{
		cout << 1;
		return (0);
	}
	for (int i = 1; i < m; i++)
		dp.push(1);
	dp.push(2);
	for (int i = m + 1; i <= n; i++)
	{
		long long tmp = dp.front() + dp.back();
		if (tmp > 1000000007) tmp %= 1000000007;
		dp.push(tmp);
		dp.pop();
	}
	cout << dp.back();
	return (0);
}