#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int			t, n;
long long		x, y;
double			ans = 0;
vector<long long>	miner, dia;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		ans = 0;
		dia.clear();
		miner.clear();
		cin >> n;
		for (int i = 0; i < 2 * n; i++)
		{
			cin >> x >> y;
			if (x == 0)
				miner.push_back(abs(y));
			else
				dia.push_back(abs(x));
		}
		sort(miner.begin(), miner.end());
		sort(dia.begin(), dia.end());
		for (int i = 0; i < n; i++)
		{
			ans += sqrt(double(miner[i] * miner[i] + dia[i] * dia[i]));
		}
		printf("%.15lf", ans);
		if (t) printf("\n");
	}
	return (0);
}
