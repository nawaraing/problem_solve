#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		maxi = 0, idx, n;
	for (int i = 1; i <= 9; i++)
	{
		cin >> n;
		if (maxi < n)
		{
			maxi = n;
			idx = i;
		}
	}
	cout << maxi << "\n" << idx;
	return (0);
}
