#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			n, k, divide = 1;
	cin >> n >> k;
	while (divide < k)
	{
		if (k % divide == 0 && k / divide + divide <= n)
			break ;
		divide++;
	}
	if (k != 1 && divide == k)
		cout << -1;
	else
	{
		for (int i = 0; i < n - k / divide - divide; i++)
			cout << 'B';
		for (int i = 0; i < divide; i++)
			cout << 'A';
		for (int i = 0; i < k / divide; i++)
			cout << 'B';
	}
	return (0);
}