#include <iostream>
#include <cmath>

using namespace std;

long long		gcd(long long a, long long b) {
	long long		tmp, n;
	
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

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long				a, b, dist, odd, d;

	cin >> a >> b;
	dist = b - a;
	odd = (long long)sqrt(b) - (long long)sqrt(a);
//	cout << "odd : " << odd << "\n";
	if (odd == 0) {
		cout << "0";
		return (0);
	}
	d = gcd(dist, odd);
//	cout << "d : " << d << "\n";
	odd /= d;
	dist /= d;
	cout << odd << "/" << dist;
	return (0);
}