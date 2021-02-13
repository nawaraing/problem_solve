#include <stdio.h>
#include <limits.h>

using namespace std;

int		n, m, r, a, b, l;
int		graph[101][101];
int		items[101];

int		main(void)
{
	scanf("%d %d %d", &n, &m, &r);
	for (int i = 1; i <= n; i++)
		scanf("%d", &items[i]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			graph[i][j] = INT_MAX;
		}
	}
	for (int i = 1; i <= r; i++)
	{
		scanf("%d %d %d", &a, &b, &l);
		graph[a][b] = l;
		graph[b][a] = l;
	}
	for (int via = 1; via <= n; via++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (via == i) continue ;
				if (via == j) continue ;
				if (j == i) continue ;
				if (graph[i][via] == INT_MAX) continue;
				if (graph[via][j] == INT_MAX) continue;
				if (graph[i][j] > graph[i][via] + graph[via][j])
					graph[i][j] = graph[i][via] + graph[via][j];
			}
		}
	}
	int		maxi = 0;
	for (int i = 1; i <= n; i++)
	{
		int		turn = items[i];
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] <= m)
			{
				turn += items[j];
			}
		}
		if (maxi < turn)
			maxi = turn;
	}
	printf("%d", maxi);
	return (0);
}
