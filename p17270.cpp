#include <iostream>
#include <queue>

using namespace std;

int			v, m, a, b, c, j, s;
int			graph[101][101], jcost[101], scost[101];
bool		visit[101];
priority_queue<pair<int, int> >		pq;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> v >> m;
	for (int i =0; i < m; i++)
	{
		cin >> a >> b >> c;
		graph[a][b] = c;
		graph[b][a] = c;
	}
	cin >> j >> s;
	for (int i = 1; i <= v; i++)
	{
		jcost[i] = 2147483647;
		scost[i] = 2147483647;
	}
	// j da-ik
	pq.push(make_pair(0, j));
	jcost[j] = 0;
	while (pq.size())
	{
		pair<int, int>	pr = pq.top();
		int				cur_idx = pr.second;
		int				cost = -pr.first;

		pq.pop();
		visit[cur_idx] = true;
		for (int i = 1; i <= v; i++)
		{
			if (graph[cur_idx][i] == 0) continue ;
			if (visit[i]) continue ;
			if (jcost[i] > cost + graph[cur_idx][i])
			{
				jcost[i] = cost + graph[cur_idx][i];
				pq.push(make_pair(-jcost[i], i));
			}
		}
	}
	while (pq.size()) pq.pop();
	for (int i = 1; i <=v ;i++) visit[i] = false;
	//	s da-ik
	pq.push(make_pair(0, s));
	scost[s] = 0;
	while (pq.size())
	{
		pair<int, int>	pr = pq.top();
		int				cur_idx = pr.second;
		int				cost = -pr.first;

		pq.pop();
		visit[cur_idx] = true;
		for (int i = 1; i <= v; i++)
		{
			if (graph[cur_idx][i] == 0) continue ;
			if (visit[i]) continue ;
			if (scost[i] > cost + graph[cur_idx][i])
			{
				scost[i] = cost + graph[cur_idx][i];
				pq.push(make_pair(-scost[i], i));
			}
		}
	}
	int		ans = -1;
	int		minn = 2147483647;
	int		dist = 2147483647;
	for (int i = 1; i <= v; i++)
	{
		if (i == j || i == s) continue ;
		// cout << "minn : " << minn << "\n";
		if (minn > scost[i] + jcost[i] && jcost[i] <= scost[i]) {
			ans = i;
			minn = scost[i] + jcost[i];
			dist = jcost[i];
		}
		else if (minn == scost[i] + jcost[i] && jcost[i] <= scost[i]) {
			if (dist > jcost[i])
			{
				ans = i;
				minn = scost[i] + jcost[i];
				dist = jcost[i];
			}
			else if (dist == jcost[i] && ans > i)
			{
				ans = i;
				minn = scost[i] + jcost[i];
			}
		}
	}
	cout << ans;
	return (0);
}