#include <iostream>

using namespace std;

int		ans = 2147483647;

void			ft_recur(int N, int cnt)
{
	if (N == 1) {
		if (ans > cnt) ans = cnt;
		return ;
	}

	cnt++;
	if (N % 3 == 0) ft_recur(N / 3, cnt);
	if (N % 2 == 0) ft_recur(N / 2, cnt);
	ft_recur(N - 1, cnt);
	return ;
}

int			main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		N;

	cin >> N;
	ft_recur(N, 0);
	cout << ans;
	return (0);
}
