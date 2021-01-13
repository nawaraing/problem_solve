#include <iostream>
#include <queue>

using namespace std;

bool				graph[1001][1001];
bool				visit[1001];
int					n, m, ans;

void	ft_bfs(int idx) {
	queue<int>		q;
	int				a;

	q.push(idx);
	while (q.size()) {
		a = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (!visit[i] && graph[a][i]) {
				visit[i] = 1;
				q.push(i);
			}
		}
	}
	return ;
}
/*
void	ft_print(void) {
	for (int i = 1; i <= n; i++) {
		cout << visit[i] << " ";
	}
	cout << "\n";
	return ;
}
*/
int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int			a, b;
		cin >> a >> b;
		graph[a][b] = graph[b][a] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			ans++;
			visit[i] = 1;
			ft_bfs(i);
//			ft_print(); //
		}
	}
	cout << ans;
	return (0);
}