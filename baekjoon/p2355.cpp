#include <iostream>
#include <algorithm>

using namespace std;

long long		ft_sigma(long long n)
{
	if (n < 0) n *= -1;
	return (n * (n + 1) / 2);
}

int				main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long		a, b;

	cin >> a; cin >> b;
	if (a < b) swap(a, b);
	if (b > 0) cout << ft_sigma(a) - ft_sigma(b - 1);
	else if (b == 0) cout << ft_sigma(a);
	else if (a > 0 && b < 0) cout << ft_sigma(a) - ft_sigma(b);
	else if (a == 0) cout << ft_sigma(b);
	else if (a < 0) cout << ft_sigma(a + 1) - ft_sigma(b);	
	else cout << "really here\n";
	return (0);
}
