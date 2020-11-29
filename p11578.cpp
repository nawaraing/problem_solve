#include <iostream>
#include <limits.h>

using namespace std;

bool		stu[11][11];
bool		take[11];
bool		sol[11];
int			minn = INT_MAX;
int			n, m, a, b;

void	ft_backtracking(int idx) {
	if (idx == m + 1) {
		int		ans = 0;
		bool	flag;

		for (int i = 1; i <= m ; i++) cout << take[i] << " ";
		cout << "\n";
		for (int i = 1; i <= n; i++) {
			flag = 0;
			for (int j = 1; j <= m; j++) {
				if (take[j] && stu[j][i]) {
					flag = 1;
					break ;
				}
			}
			if (!flag) return ; 
		}
		for (int i = 1; i <= n; i++) {
			if (take[i]) ans++;
		}
		if (minn > ans) minn = ans;
		return ;
	}

	for (int i = idx; i <= m; i++) {
		take[i] = 1;
		ft_backtracking(i + 1);
		take[i] = 0;
	}
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a;
		while (a--) {
			cin >> b;
			stu[i][b] = 1;
			sol[b] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!sol[i]) {
			cout << -1;
			return (0);
		}
	}
	ft_backtracking(1);
	cout << minn;
	return (0);
}