#include <iostream>

using namespace std;

long long			num;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> num;
	long long sum = 0;
	long long ans = 0;
	for (int i = 0; i < num + 2; i++)
	{
		sum += i;
		if (sum > num)
		{
			ans = i;
			break ;
		}
	}
	cout << ans - 1;
	return (0);
}