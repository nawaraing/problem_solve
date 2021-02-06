#include <iostream>

using namespace std;

int		n, node[10];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	char c;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		node[((int)c - '0')]++;
		cin >> c;
		node[((int)c - '0')]++;
	}
	long long		ans = 1;
	for (int i = 0; i < 10; i++)
	{
		// cout << node[i] << " ";
		if (node[i] == 2)
			ans *= 1;
		else if (node[i] == 4)
			ans *= 3;
		else if (node[i] == 6)
			ans *= 15;
		else if (node[i] == 8)
			ans *= 105;
		else if (node[i] % 2) ans = 0;
	}
	cout << ans;
	return (0);
}