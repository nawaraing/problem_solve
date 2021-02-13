#include <stdio.h>

using namespace std;

int			n, m, a, b;
int			graph[101][101];

int		main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
	}
	for (int via = 1; via <= n; via++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (via == i) continue ;
				if (via == j) continue ;
				if (i == j) continue ;
				if (graph[i][j]) continue ;
				if (graph[i][via] && graph[via][j])
				{
					graph[i][j] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int		prt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] == 0 && graph[j][i] == 0)
				prt++;
		}
		printf("%d\n", prt - 1);
		// printf("\n");
	}
	return (0);
}
