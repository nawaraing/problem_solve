#include <iostream>
#include <cmath>

using namespace std;

int		n, arr[10002], one[10002], two[10002];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	one[1] = arr[1];
	one[2] = arr[2];
	for (int i = 1; i <= n; i++)
	{
		two[i + 1] = one[i] + arr[i + 1];
		one[i + 2] = max(two[i] + arr[i + 2], one[i] + arr[i + 2]);
	}
	// for (int i = 0; i <=n + 1;i++) cout << two[i] << " ";
	// cout << "\n";
	// for (int i = 0; i <=n + 1;i++) cout << one[i] << " ";
	// cout << "\n";
	cout << max(max(one[n - 1], two[n - 1]), max(one[n], two[n]));
	return (0);
}