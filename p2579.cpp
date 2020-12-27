#include <iostream>

using namespace std;

int		n, a, one[301], two[301], stair[301];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		stair[i] = a;
	}
	if (n == 1)
	{
		cout << stair[1];
		return (0);
	}
	two[1] = stair[1];
	two[2] = stair[2];
	for (int i = 1; i <=n; i++)
	{
		one[i + 1] = two[i] + stair[i + 1];
		if (two[i] > one[i]) two[i + 2] = two[i] + stair[i + 2];
		else two[i + 2] = one[i] + stair[i + 2];
	}
	if (one[n] > two[n]) cout << one[n];
	else cout << two[n];
	return (0);
}