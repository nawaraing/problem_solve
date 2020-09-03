#include <iostream>

using namespace std;

int		ans = 0;

void				ft_recur(int i, int digit, int N)
{
	if (N == 1) {
		ans++;
		return ;
	}
	if (i != 0) ft_recur(i - 1, digit + 1, N - 1);
	if (i != 9) ft_recur(i + 1, digit + 1, N - 1);
	return ;
}

int				main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		N;

	cin >> N;
	for (int i = 1; i < 10; i++)
		ft_recur(i, 1, N);
	cout << ans;
	return (0);
}
