#include <iostream>
#include <limits.h>
#include <cmath>

using namespace std;

int				n, s[20][20], dist = INT_MAX;
bool			member[20];

void	ft_power(void) {
	int		t0 = 0, t1 = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (member[i] == member[j]) {
				if (member[i]) t1 += s[i][j] + s[j][i];
				else t0 += s[i][j] + s[j][i];
			}
		}
	}
	if (abs(t0 - t1) < dist) dist = abs(t0 - t1);
}

void	ft_backtracking(int mem_cnt, int idx) {
	if (mem_cnt == n / 2) {
		ft_power();
		return ;
	}

	for (int i = idx; i < n; i++) {
		member[i] = 1;
		ft_backtracking(mem_cnt + 1, i + 1);
		if (dist == 0) return ;
		member[i] = 0;
	}
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}
	ft_backtracking(0, 0);
	cout << dist;
	return (0);
}