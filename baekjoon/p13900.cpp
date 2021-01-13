#include <iostream>

using namespace std;

long long		nums[100001], sums[100001], n, a;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> nums[i];
		sums[i] = sums[i - 1] + nums[i];
	}
	long long		ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += nums[i] * (sums[n] - sums[i]);
	}
	cout << ans;
	return (0);
}