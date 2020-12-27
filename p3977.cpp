#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int				t, n, m, a, b;
stack<int>		st;
vector<int>		graph[100000], rev[100000], tmp;
vector<vector<int> >	new_graph, nodes;
bool			visit[100000];
int				rece[100000];

void	dfs(int node)
{
	visit[node] = true;
	for (int i = 0; i < graph[node].size(); i++)
	{
		if (visit[graph[node][i]]) continue ;
		dfs(graph[node][i]);
	}
	st.push(node);
}

void	dfs_rev(int node)
{
	visit[node] = true;
	for (int i = 0; i < rev[node].size(); i++)
	{
		if (visit[rev[node][i]]) continue ;
		dfs(rev[node][i]);
	}
	tmp.push_back(node);
}

void	scc(void)
{
	for (int i = 0;i < n; i++)
	{
		if (visit[i]) continue ;
		dfs(i);
	}
	for (int i = 0; i < n; i++) visit[i] = false;
	int		num = 0;
	while (st.size())
	{
		int		node = st.top();
		st.pop();
		if (visit[node]) continue ;
		tmp.clear();
		dfs_rev(node);
		nodes.push_back(tmp);
		num++;
	}
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			visit[i] = false;
			graph[i].clear();
			rev[i].clear();
		}
		while (m--)
		{
			cin >> a >> b;
			graph[a].push_back(b);
			rev[b].push_back(a);
		}
		scc();
/* 		cout << "st : ";
		while (st.size())
		{
			cout << st.top() << " ";
			st.pop();
		}
 */	}
	return (0);
}