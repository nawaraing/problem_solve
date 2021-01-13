#include <iostream>

using namespace std;

int			status[11][11], maxi;
bool		pos[11];

bool	ft_isfull(void) {
	for (int i = 0; i < 11; i++) if (!pos[i]) return false;
	return true;
}


void	ft_backtracking(int idx, int cost) {
	if (ft_isfull()) {
		if (maxi < cost) maxi = cost;
		return ;
	}
	for (int i = 0; i < 11; i++) {
		if (pos[i]) continue ;
		if (status[idx][i]) {
			pos[i] = true;
			ft_backtracking(idx + 1, cost + status[idx][i]);
			pos[i] = false;
		}
	}
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			t;
	
	cin >> t;
	while (t--) {
		maxi = 0;
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				cin >> status[i][j];
			}
		}
		for (int i = 0; i < 11; i++) pos[i] = 0;
		ft_backtracking(0, 0);				//  idx, position, cost
		cout << maxi << "\n";
	}

	return (0);
}