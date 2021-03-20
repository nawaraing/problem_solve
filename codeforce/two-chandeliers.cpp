#include <iostream>

using namespace std;

long long		n, m, k;

long long		gcd(long long a, long long b)
{
	long long		tmp;
	if (a < b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	while (b)
	{
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int		prime[500001];
#include <vector>
vector<int>		v;
int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	long long		roop = n * m / gcd(n, m);
	return (0);
}
	// for (int i = 2; i <= 500000; i++)
	// {
	// 	if (prime[i] == 1)
	// 		continue;
	// 	v.push_back(i);
	// 	for (int j = 1; j * i <= 500000; j++)
	// 		prime[i * j] = 1;
	// }
	// cout << v[v.size() - 1] << " " << v[v.size() - 2] << "\n";
