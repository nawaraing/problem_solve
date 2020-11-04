#include <iostream>

using namespace std;

int					dots[10001];
int					leng, idx, maxi = 0, cnt, ret;
int					l, k, c, a;
bool				visit[10001];

void	ft_dfs(int pre, int i) {
	if (cnt == c) {
		if (ret > maxi) ret = maxi;
		return ;
	}
	if (i == k) return ;

	visit[i] = 1;
	cnt++;
	if (dots[pre] - dots[i] > maxi) {
		maxi = dots[pre] - dots[i];
	}
	ft_dfs(i, i + 1);
	visit[i] = 0;
	cnt--;
	ft_dfs(pre, i + 1);
	return ;
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> l >> k >> c;
	for (int i = 1; i <= k; i++) {
		cin >> a;
		dots[i] = a;
	}
	ft_dfs(0, 1);
	cout << ret << " ";
	return (0);
}