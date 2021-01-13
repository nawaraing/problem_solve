#include <iostream>

using namespace std;

int			n;
bool		movie[64][64];

void	ft_dfs(int c, int r, int size) {
	int			dist = size / 2;
	bool		flag, flag2 = false;

//	printf("c : %d  r : %d  size : %d\n", c, r, size);

	if (size == 1) {
		cout << movie[c][r];
		return ;
	}

	flag = movie[c][r];
	for (int i = c; i < c + size; i++) {
		for (int j = r; j < r + size; j++) {
			if (flag != movie[i][j]) {
				flag2 = true;
				break;
			}
		}
		if (flag2) break ;
	}
	if (flag2) {
		cout << "(";
		ft_dfs(c, r, dist);
		ft_dfs(c, r + dist, dist);
		ft_dfs(c + dist, r, dist);
		ft_dfs(c + dist, r + dist, dist);
		cout << ")";
	}
	else {
		if (flag) cout << 1;
		else cout << 0;
	}
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	char			c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			if (c == '1') movie[i][j] = true;
			else movie[i][j] = false;
		}
	}
	ft_dfs(0, 0, n);
	return (0);
}