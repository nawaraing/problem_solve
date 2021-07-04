#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int	n;
	
	cin >> n;
	cout << n * (n + 1) / 2;

	return (0);
}
