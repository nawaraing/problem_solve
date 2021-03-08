#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

int							n, m, l, k;
vector<pair<int, int> >		v;		// y, x
int							choice;


int		in_the_box(int x, int y)
{
	if (abs(x - v[choice].second) > l)
		return 0;
	if (abs(y - v[choice].first) > l)
		return 0;
	return 1;
}

int		main(void)
{
	scanf("%d %d %d %d\n", &n, &m, &l, &k);
	for (int i = 0; i < k; i++)
	{
		int		x, y;
		scanf("%d %d", &x, &y);
		if (i != k - 1)
			scanf("\n");
		v.push_back(make_pair(y, x));
	}
	sort(v.begin(), v.end());
	int		maxi = 0;
	for (choice = 0; choice < k; choice++)
	{
		for (int i = choice; i < k; i++)
		{
			if (in_the_box(v[i].second, v[i].first) == 0)
				continue ;
			int	cnt = 0;
			for (int j = i; j < k; j++)
			{
				if (in_the_box(v[j].second, v[j].first) == 0)
					continue ;
				if (v[j].second - v[i].second > l)
					continue ;
				cnt++;
			}
			if (maxi < cnt) maxi = cnt;
		}
	}
	printf("%d\n", k - maxi);
	return (0);
}