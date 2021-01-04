#include <iostream>
#include <vector>

using namespace std;

int		n ,u, v, street[300001];
unsigned long long dcnt;
vector<int>		graph[300001];
int		visit[300001];

// void	ft_dfs(int node, int except)
// {
// 	visit[node] = 1;
// 	if (graph[node].size() > 2)
// 		street[graph[node].size()]++;
// 	if (except == 0)
// 		dcnt++;
// 	else except--;
// 	for (int i = 0; i < graph[node].size(); i++)
// 	{
// 		if (visit[graph[node][i]]) continue ;
// 		ft_dfs(graph[node][i], except);
// 	}
// }

void	ft_start(int node, int except)
{
	visit[node] = 1;
	if (graph[node].size() > 2)
		street[graph[node].size()]++;
	if (except == 0)
		dcnt++;
	else except--;
	unsigned long long		two_cnt = 0, two = 0, one = 0;
	for (int i = 0; i < graph[node].size(); i++)
	{
		int		next = graph[node][i];
		if (visit[next]) continue ;
		if (graph[next].size() == 1) one++;
		else if (graph[next].size() > 1) {
			two_cnt++;
			two += graph[next].size() - 1;
		}
		ft_start(next, except);
	}
	// cout << two << " " << two_cnt << " " << one << "\n";
	dcnt += (two) * (two_cnt - 1 + one);
}

unsigned long long		nc3(int i)
{
	unsigned long long ret = i * (i - 1) * (i - 2);
	ret /= 6;
	return ret;
}

unsigned long long		ft_cnt_gtree(void)
{
	unsigned long long 		ret = 0;
	for (int i = 3; i <= n; i++)
	{
		// cout << "street[" << i << "] = " << street[i] << "\n";
		if (street[i] == 0) continue;
		ret += street[i] * nc3(i);
		// cout << "ret : " << ret << "\n";
	}
	return ret;
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	ft_start(u, 3);
	unsigned long long		gcnt = ft_cnt_gtree();
	// cout << dcnt << " " << gcnt << "\n";
	if (dcnt == gcnt * 3)
		cout << "DUDUDUNGA";
	else if (dcnt < gcnt * 3)
		cout << "G";
	else cout << "D";
	return (0);
}