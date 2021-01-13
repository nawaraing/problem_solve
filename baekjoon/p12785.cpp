#include <iostream>

using namespace std;

long long		ft_gcd(long long a, long long b) {
	long long			tmp, n;
	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	while (b != 0) {
		n = a % b;
		a = b;
		b = n;
	}
	return (a);
}

long long		ft_ncr(int n, int r) {
	long long			down = 1;
	long long			up = 1;
	long long			d;

	while (r--) {
		up *= n--;
		down *= (r + 1);
		if ((d = ft_gcd(up, down)) != 1) {
			up /= d;
			down /= d;
		}
	}
	return (up);
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			w, h, x, y, a, b;

	cin >> w >> h >> x >> y;
	a = x - 1;
	b = y - 1;
	long long		ret = ft_ncr(a + b, a) % 1000007;
//	cout << "Ret : " << ret << "\n";
	a = w - x;
	b = h - y;
	ret *= ft_ncr(a + b, a) % 1000007;
	ret %= 1000007;
	cout << ret;
	return (0);
}