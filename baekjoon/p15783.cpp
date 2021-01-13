#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int			n, m, a, b, num = 0;
vector<int>	origi[100001], rev[100001], group, line;
vector<vector<int> >	sets, graph;
stack<int>				st;
int						visit[100001];
bool					rece[100001];

void	scc(int node)
{
	for (int i  = 0; i < origi[node].size(); i++)
	{
		if (visit[origi[node][i]]) continue ;
		visit[origi[node][i]] = true;
		scc(origi[node][i]);
	}
	st.push(node);
	// cout << st.top() << " ";
}

void		scc_rev(int node)
{
	visit[node] = num;
	group.push_back(node);
	for (int i = 0; i < rev[node].size(); i++)
	{
		if (visit[rev[node][i]] != -1) {
			if (num != visit[rev[node][i]])
				line.push_back(visit[rev[node][i]]);
			continue ;
		}
		scc_rev(rev[node][i]);
	}
}

int		main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0 ; i < m; i++)
	{
		cin >> a >> b;
		origi[a].push_back(b);
		rev[b].push_back(a);
		rece[b] = true;
	}
	// cout << "stack : ";
	for (int i = 0; i < n; i++)
	{
		if (visit[i] || rece[i]) continue ;
		visit[i] = 1;
		scc(i);
	}
	for (int i = 0; i < n; i++)
	{
		if (visit[i]) continue ;
		visit[i] = 1;
		scc(i);
	}
	// cout << "\n";
	for (int i = 0; i < n; i++) visit[i] = -1;
	while (!st.empty())
	{
		if (visit[st.top()] != -1) {
			st.pop();
			continue ;
		}
		group.clear();
		line.clear();
		scc_rev(st.top());
		sets.push_back(group);
		graph.push_back(line);
		num++;
		st.pop();
/* 		cout << "visit : ";
		for (int i  = 0; i < n; i++) cout << visit[i] << " ";
		cout << "\n";
 */	}
/* 	cout << "( sets ) : graph\n";
	for (int i = 0; i < graph.size(); i++)
	{
		cout << "( ";
		for (int j = 0; j < sets[i].size(); j++) cout << sets[i][j] << " ";
		cout << ") : ";
		for (int j = 0; j < graph[i].size(); j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	} */
	int		ans = 0;
	// cout << "graph size : " << graph.size() << "\n";
	for (int i = 0; i < graph.size(); i++)
	{
		if (graph[i].size() == 0) ans++;
	}
	cout << ans;
	return (0);
}