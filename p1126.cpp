#include <iostream>

using namespace std;

int				maxi, n, block[50], used[50], total = 0;

void	ft_backtracking(int a, int b, int idx) {
	if (a == b && maxi < a) maxi = a;
	if (idx == n || a > total / 2 || b > total / 2) return ;

	ft_backtracking(a, b, idx + 1);
	used[idx] = 1;
	ft_backtracking(a + block[idx], b, idx + 1);
	used[idx] = 2;
	ft_backtracking(a, b + block[idx], idx + 1);
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> maxi;
		block[i] = maxi;
		total += maxi;
	}
	maxi = 0;
	ft_backtracking(0, 0, 0);
	cout << maxi;
	return (0);
}