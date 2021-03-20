#include <iostream>

using namespace std;

unsigned long long		perfect = 18446744073709551615ULL, num;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		cnt = 0;
	cin >> num;
	num = perfect - num + 1;
	while (num % 2 == 0)
	{
		num /= 2;
		cnt++;
	}
	cout << 64 - cnt;
	return (0);
}