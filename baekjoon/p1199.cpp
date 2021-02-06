#include <iostream>
#include <vector>

using namespace std;

int			n, graph[1001][1001], degree[1001];
vector<int>	v, ans;

int		ft_dfs(int start, int node)
{
	if (node == start) {
		v.push_back(node);
		return 1;
	}
	if (node == -1)
		node = start;
	for (int i = 1; i <= n; i++)
	{
		if (graph[node][i]) {
			graph[node][i]--;
			graph[i][node]--;
			if (ft_dfs(start, i)) {
				degree[node] -= 2;
				v.push_back(node);
				return 1;
			}
		}
	}
	return 0;
}

void	ft_euler(int start)
{
	v.clear();
	ft_dfs(start, -1);
	vector<int>		tmp = v;
	for (int i = 0; i < tmp.size(); i++)
	{
		if (degree[tmp[i]])
		{
			ft_euler(tmp[i]);
		}
		else ans.push_back(tmp[i]);
	}
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	int		odd = 0;
	for (int i = 1; i <= n; i++)
	{
		int		sum = 0;
		for (int j = 1; j <= n; j++)
		{
			cin >> graph[i][j];
			sum += graph[i][j];
		}
		degree[i] = sum;
		if (sum % 2) odd++;
	}
	if (n == 1){
		cout << 1;
		return (0);
	}
	if (odd)
		cout << -1;
	else
	{
		ft_euler(1);
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i];
			if (i != ans.size() - 1) cout << " ";
		}
	}
	return (0);
}