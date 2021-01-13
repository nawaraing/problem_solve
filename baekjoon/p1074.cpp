#include <iostream>
#include <cmath>

using namespace std;

int			n, r, c, ret = 0;

void	ft_dfs(int n, int r, int c) {
	int			dist = 0;

	if (n == 0) return ;
	dist = pow(2, 2 * (n - 1));
	int 		side = pow(2, n);
	if (side / 2 > r && side / 2 > c) ft_dfs(n - 1, r, c);
	else if (side / 2 > r && side / 2 <= c) {
		ft_dfs(n - 1, r, c - side / 2);
		ret += dist;
	}
	else if (side / 2 <= r && side / 2 > c) {
		ft_dfs(n - 1, r - side / 2, c);
		ret += 2 * dist;
	}
	else {
		ft_dfs(n - 1, r - side / 2, c - side / 2);
		ret += 3 * dist;
	}
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> r >> c;
	ft_dfs(n, r, c);
	cout << ret;
	return (0);
}