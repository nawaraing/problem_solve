#include <iostream>
//#include <vector>
#include <queue>
//#include <stack>
//#include <list>
//#include <algorithm>

using namespace std;

int			dfs[1000][1000];
int			bfs[1000][1000];
int			nums[1000];
int			num[1000];
queue<int>	q;

void	ft_print(int n, int mat[][1000]) 
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << " " << mat[i][j];
		}
		cout << "\n";
	}
	return ;
}

void	ft_dfs(int n, int pt)
{
//	cout << "n : " << n << "  cnt : " << cnt << "\n";
	for (int i = 0; i < n; i++) {
		if (dfs[pt][i] && !num[i]) {
			cout << " " << i + 1;
			num[i] = 1;
			ft_dfs(n, i);
		}
	}
	return ;
}

void	ft_bfs(int n, int pt)
{
	for (int i = 0; i < n; i++) {
		if (bfs[pt][i] && !nums[i]) {
			q.push(i);
			nums[i] = 1;
		}
	}
	cout << pt + 1;
	while (q.size()) {
		cout << " " << q.front() + 1;
		for (int i = 0; i < n; i++) {
			if (bfs[q.front()][i] && !nums[i]) {
				q.push(i);
				nums[i] = 1;
			}
		}
		q.pop();
	}
	return ;
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			n, m, v, a, b;

	cin >> n >> m >> v;   // dots  lines  start-point

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		dfs[a - 1][b - 1] = 1;
		dfs[b - 1][a - 1] = 1;
		bfs[a - 1][b - 1] = 1;
		bfs[b - 1][a - 1] = 1;
	}
//	ft_print(n, mat);
	num[v - 1] = 1;
	cout << v;
	ft_dfs(n, v - 1);
//	ft_print(n, mat);
	cout << "\n";
	nums[v - 1] = 1;
	ft_bfs(n, v - 1);
	return (0);
}