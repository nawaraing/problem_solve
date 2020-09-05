#include <iostream>

using namespace std;

int		ft_fibo(int n)
{
	if (n == 0) return 0;
	else if (n == 1) return 1;
	return (ft_fibo(n - 1) + ft_fibo(n - 2));
}
	

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int	n;

	cin >> n;
	cout << ft_fibo(n);
	return (0);
}
