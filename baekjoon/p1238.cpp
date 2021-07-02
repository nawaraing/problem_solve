#include <iostream>
#include <set>

using namespace std;

int			n, m, x, a, b, c;
int			graph[1001][1001];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> x;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			graph[i][j] = 2147483647;
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		graph[a][b] = c;
	}
	// cout << "input done!" << endl;
	for (int row = 1; row <= n; row++)
	{
		set<int> s;
		s.insert(row);
		while (s.size() < n)
		{
			// cout << "s size: " << s.size() << endl;
			int		minn = 2147483647;
			int		cur = 0;
			for (int i = 1; i <= n; i++)
			{
				if (s.find(i) != s.end())
					continue ;
				if (minn > graph[cur][i])
				{
					minn = graph[row][i];
					cur = i;
				}
			}
			// cout << "cur: " << cur << endl;
			s.insert(cur);
			for (int i = 1; i <= n; i++)
			{
				if (s.find(i) != s.end()) continue ;
				if (graph[cur][i] == 2147483647) continue ;
				int cur_cost = graph[cur][i] + graph[row][cur];
				if (graph[row][i] > cur_cost)
					graph[row][i] = cur_cost;
			}
		}
	}
	int		ans = 0;
/* 	for (int i = 0; i <=n ;i++)
	{
		for (int j =0; j <=n; j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
 */	for (int i = 1; i <= n; i++)
	{
		if (i == x) continue ;
		if (ans < graph[x][i] + graph[i][x])
			ans = graph[x][i] + graph[i][x];
	}
	cout << ans;
	return (0);
}