#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int						ans[100001];
vector<vector<int> >	graph;

int		n, a, b;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	vector<int>	tmp;
	for (int i = 0; i <= n; i++)
		graph.push_back(tmp);
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	queue<int>	q;
	q.push(1);
	while (!q.empty())
	{
		int		parent = q.front();
		q.pop();

		for (unsigned int i = 0; i < graph[parent].size(); i++)
		{
			int		child = graph[parent][i];
			if (ans[child] != 0) continue ;
			ans[child] = parent;
			q.push(child);
		}
	}
	for (int i = 2; i <= n; i++)
	{
		cout << ans[i];
		if (i != n) cout << endl;
	}
	return (0);
}