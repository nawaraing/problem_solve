#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>

using namespace std;

int		n, m, cnt, visit[1001];
double	 a, b, ans;
pair<double, double>	stars[1001];
vector<int>			graph[1001];
priority_queue<pair<double, pair<int, int> > >	pq;

double	ft_dist(pair<double, double> a, pair<double, double> b)
{
	double	ff = abs(a.first - b.first);
	double	ss = abs(a.second - b.second);
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
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf %lf", &a, &b);
		stars[i] = make_pair(a, b);
	}
	for (int i = 0; i < m; i++)
	{
		int		c, d;
		scanf("%d %d", &c, &d);
		if (c == d) continue ;
		memset(visit, 0, sizeof(visit));
		if (ft_dfs(c, d))
		{
			graph[c].push_back(d);
			graph[d].push_back(c);
			cnt++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			pq.push(make_pair(-ft_dist(stars[i], stars[j]), make_pair(i, j)));
		}
	}
	while (!pq.empty())
	{
		int		begin = pq.top().second.first;
		int		dest = pq.top().second.second;
		memset(visit, 0 ,sizeof(visit));
		if (ft_dfs(begin, dest))
		{
			graph[begin].push_back(dest);
			graph[dest].push_back(begin);
			cnt++;
			ans -= pq.top().first;
		}
		if (cnt == n - 1) break ;
		pq.pop();
	}
	printf("%.2lf", ans);
	return (0);
}
