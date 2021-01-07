#include <iostream>
#include <cmath>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long			m, seed, x1, x2, divide, one, two;

	cin >> m >> seed >> x1 >> x2;
	if (seed == x1)
	{
		cout << "1 0";
		return (0);
	}
	divide = seed - x1;
	one = (x1 - x2) % m;
	// two = (seed * x2 - (x1 * x1)) % m;
	if (divide < 0)
	{
		divide *= -1;
		one *= -1;
		// two *= -1;
	}
	if (one < 0) one += m;
	// if (two < 0) two += m;
	while (one % divide)
		one += m;
	one /= divide;
	one %= m;
	// while (two % divide)
	// 	two += m;
	// two /= divide;
	// two %= m;
	two = x1 - one * seed;
	two %= m;
	if (two < 0) two += m;
	cout << one << " " << two;
	return (0);
}