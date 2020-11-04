#include <iostream>

using namespace std;

void	ft_test(int a[2][2])
{
	a[0][0] = 1;
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		a[2][2];

	a[0][0] = 0;
	ft_test(a);
	cout << a[0][0] << "\n";
	return (0);
}