#include <iostream>
#include <map>

using namespace std;

map<pair<int, int>, int>	m;
map<pair<int, int>, int>::iterator		it;
int						n;
int						a, b, d;
pair<int, int>			pr;

int		gcd(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a < b)
	{
		int	tmp = a;
		a = b;
		b = tmp;
	}
	int		r = a % b;
	if (r != 0)
		b = gcd(b, r);
	return (b);
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int		ret = 1;

	cin >> n;
	while (n--)
	{
		cin >> a >> b;
		if (a == 0 || b == 0)
		{
			if (a != 0 && a > 0)
				d = a;
			else if (a != 0 && a < 0)
				d = -a;
			else if (b != 0 && b > 0)
				d = b;
			else if (b != 0 && b < 0)
				d = -b;
			else d = 1;
		}
		else
			d = gcd(a, b);
		a /= d;
		b /= d;
		// cout << a << " " << b << "\n";
		pr = make_pair(a, b);
		it = m.find(pr);
		if (it == m.end())
			m.insert(make_pair(pr, 1));
		else
		{
			m[pr]++;
			if (m[pr] > ret) {
				ret = m[pr];
				// cout << pr.first << " " << pr.second << "\n";
			}
		}
	}
	cout << ret;
	return (0);
}