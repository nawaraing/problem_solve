#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int		n, m, a, b;
int		receive[32001];
vector<vector<int> >	graph;
priority_queue<int, vector<int>, greater<int> >				q;
vector<int>				ans;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	vector<int>	tmp;
	for (int i = 0; i <= n; i++)
		graph.push_back(tmp);
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		receive[b]++;
	}
	for (int i = 1; i <= n; i++)
		if (receive[i] == 0)
			q.push(i);
	while (!q.empty())
	{
		int		node = q.top();
		q.pop();

		ans.push_back(node);
		sort(graph[node].begin(), graph[node].end());
		for (int i = 0; i < graph[node].size(); i++)
		{
			int		child = graph[node][i];
			receive[child]--;
			if (receive[child] == 0)
				q.push(child);
		}
	}
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i];
		if (i != ans.size() - 1)
			cout << " ";
	}
	return (0);
}