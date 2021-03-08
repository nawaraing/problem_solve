#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

int							n, m, l, k;
vector<pair<int, int> >		v;

int		main(void)
{
	scanf("%d %d %d %d\n", &n, &m, &l, &k);
	for (int i = 0; i < k; i++)
	{
		int		x, y;
		scanf("%d %d", &x, &y);
		if (i != k - 1)
			scanf("\n");
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end());
	int		maxi = 0;
	for (int frontx = 0; frontx < k; frontx++)
	{
		vector<int>		yy;
		int		backx;
		for (backx = frontx; backx < k; backx++)
		{
			if (v[backx].first - v[frontx].first > l)
				break ;
			yy.push_back(v[backx].second);
			// printf("%d ", yy.back());
		}
		// printf("\nfrontx: %d, backx: %d\n", frontx, backx);
		sort(yy.begin(), yy.end());
		int		backy, fronty;
		for (fronty = 0; fronty < yy.size(); fronty++)
		{
			for (backy = fronty; backy < yy.size(); backy++)
			{
				if (yy[backy] - yy[fronty] > l)
					break ;
			}
			int		cnt = backy - fronty;
			if (maxi < cnt) maxi = cnt;
			// printf("fronty: %d, backy: %d, cnt: %d\n", fronty, backy, cnt);
		}
	}
	printf("%d\n", k - maxi);
	return (0);
}