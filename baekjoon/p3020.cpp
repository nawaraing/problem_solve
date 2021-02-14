#include <stdio.h>

using namespace std;

int		n, h, o;
int		obs[200001];
int		up[500001], down[500001];

int		main(void)
{
	scanf("%d %d\n", &n, &h);
	// printf("%d %d\n", n, h);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &o);
		if (i % 2)
			down[o]++;
		else
			up[o]++;
	}
	for (int i = h - 1; i >= 1; i--)
	{
		down[i] += down[i + 1];
		up[i] += up[i + 1];
	}
	int		minn = 300000;
	int		cnt = 0;
	for (int i = 1; i <= h; i++)
	{
		if (minn > up[i] + down[h - i + 1])
		{
			minn = up[i] + down[h - i + 1];
			cnt = 1;
		}
		else if (minn == up[i] + down[h - i + 1])
			cnt++;
	}
	printf("%d %d", minn, cnt);
}