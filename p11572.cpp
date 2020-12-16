#include <iostream>

using namespace std;

long long			angle[360000];
bool				isdot[360000];
long long			n, r, a, tri, righ, obtuse;

long long	nc3(long long n)
{
	return (n * (n - 1) * (n - 2) / 6);
}

long long	nc2(long long n)
{
	return (n * (n - 1) / 2);
}

int		main(void)
{
	cin >> n >> r;
	int		dot = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		isdot[a] = true;
	}
	for (int i = 0; i < 360000; i++)
	{
		if (isdot[i])
			dot++;
		angle[i] = dot;
	}
	tri = nc3(n);
	for (int i = 0; i < 180000; i++)
	{
		if (isdot[i] && isdot[i + 180000])
		{
			righ += n - 2;
		}
		if (isdot[i])
		{
			obtuse += nc2(angle[i + 180000 - 1] - angle[i]);
		}
		if (isdot[i + 180000])
		{
			if (i != 0)
				obtuse += nc2((angle[360000 - 1] - angle[i + 180000] + angle[i - 1]));
			else
				obtuse += nc2((angle[360000 - 1] - angle[i + 180000]));
		}
	}
	cout << (tri - righ - obtuse);
	return (0);
}