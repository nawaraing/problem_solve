#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int				n, m, ret = 0, cnt = 0;
vector<int>		graph[1001];			//	<dot, cost> choice set

int		ft_bfs(vector<int> v) {
	queue<int>		q;
	int				visit[1001];

	for (int i = 1; i <= n; i++)
		visit[i] = 0;
	q.push(v[1]);
	while (q.size()) {
		int	a = q.front();
		q.pop();
		for (int i = 0; i < graph[a].size(); i++) {
			if (!visit[graph[a][i]])
			{
				if (graph[a][i] == v[2]) return (-1);			//	cycle
				visit[graph[a][i]] = 1;
				q.push(graph[a][i]);
			}
		}
	}
	graph[v[1]].push_back(v[2]);
	graph[v[2]].push_back(v[1]);
	cnt++;
	ret -= v[0];
	if (cnt == n - 1) return (100);								//	spanning tree done!
	return (1);													//	add line
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int								a, b, c;
	priority_queue<vector<int> >	pq;					//	order : least cost e [cost, a, b]
	vector<int>						v;

	cin >> n >> m;
	while (m--) {
		cin >> a >> b >> c;
		if (a == b) continue ;
		v.clear();
		v.push_back(-c);
		v.push_back(a);
		v.push_back(b);
		pq.push(v);
	}
	while (pq.size()) {
		if (100 == ft_bfs(pq.top())) break ;
		pq.pop();
	}
	cout << ret;
	return (0);
}