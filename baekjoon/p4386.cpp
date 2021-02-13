#include <vector>
#include <cmath>
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int					n, cnt = 0;
vector<int>			graph[101];
float				x, y, ans = 0;
pair<float, float>	stars[101];
int					visit[101];
priority_queue<pair<float, pair<int, int> > >	pq;	// < -dist sq, < x, y > >

float	ft_dist(pair<float, float> a, pair<float, float> b)
{
	float	ff = abs(a.first - b.first);
	float	ss = abs(a.second - b.second);
	return (sqrt(ff * ff + ss * ss));
}

int		ft_dfs(int begin, int dest)
{
	visit[begin] = 1;
	for (int i = 0; i < graph[begin].size(); i++)
	{
		if (visit[graph[begin][i]])
			continue ;
		if (graph[begin][i] == dest)
			return (0);
		if (0 == ft_dfs(graph[begin][i], dest))
			return (0);
	}
	return (1);
}

int		main(void)
{
	scanf("%d", &n);
	for (int i =0; i < n; i++)
	{
		scanf("%f %f\n", &x, &y);
		stars[i] = make_pair(x, y);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			pq.push(make_pair(-ft_dist(stars[i], stars[j]), make_pair(i, j)));
		}
	}
	while (!pq.empty())
	{
		int		begin = pq.top().second.first;
		int		dest = pq.top().second.second;
		memset(visit, 0, sizeof(visit));
		if (ft_dfs(begin, dest))
		{
			graph[begin].push_back(dest);
			graph[dest].push_back(begin);
			ans -= pq.top().first;
			cnt++;
		}
		if (cnt == n - 1) break ;
		pq.pop();
	}
	printf("%.2f", ans);
	return (0);
}