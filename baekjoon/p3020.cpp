#include <stdio.h>

using namespace std;

int		n, h, o;
int		obs[200001];
int		up[500001], down[500001];

int		main(void)
{
	scanf("%d %d", n, h);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", o);
		if (i % 2)
			down[o]++;
		else
			up[o]++;
	}
	for (int i = h - 1; i > 1; i--)
	{
		
	}
}