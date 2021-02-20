#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

int					graph[53][53];
int					n;
int					visit[53];

int		ft_dfs(int node, int capacity)
{
	if (node == 51)
		return (capacity);

	int		flag = 0;
	int		idx = -1;
	visit[node] = 1;
	for (int i = 0; i < 52; i++)
	{
		if (visit[i]) continue ;
		if (graph[node][i])
		{
			int		ret = capacity;
			if (ret > graph[node][i])
				ret = graph[node][i];
			if ((ret = ft_dfs(i, ret)))
			{
				idx = i;
				flag = 1;
				capacity = ret;
				break ;
			}
		}
	}
	if (flag)
	{
		graph[node][idx] -= capacity;
		graph[idx][node] += capacity;
		visit[node] = 0;
		return (capacity);
	}
	visit[node] = 0;
	return (0);
}

int		main(void)
{
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		char			c1, c2;
		int				num;
		scanf("%c %c %d", &c1, &c2, &num);
		if (i != n - 1)
			scanf("\n");
		if (c1 >= 'a' && c1 <= 'z')
			c1 -= 'a';
		else
			c1 = c1 - 'A' + 26;
		if (c2 >= 'a' && c2 <= 'z')
			c2 -= 'a';
		else
			c2 = c2 - 'A' + 26;
		if (c1 == c2) continue ;
		// printf("c: %d %d %d\n", (int)c1, (int)c2, num);
		graph[(int)c1][(int)c2] += num;
		graph[(int)c2][(int)c1] += num;
	}
	int			before = 0;
	int			after = 0;
	for (int i = 0; i < 52; i++)
		before += graph[51][i];
	// printf("before: %d\n", before);
	if (before == 0)
	{
		printf("0");
		return (0);
	}
	while (ft_dfs(26, 2147483647)) 0;
	for (int i = 0; i < 52; i++)
		after += graph[51][i];
	// printf("after: %d\n", after);
	printf("%d", after - before);
	return (0);
}