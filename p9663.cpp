#include <iostream>

using namespace std;

int				board[16], cnt = 0, n;
bool			flag;

void	ft_backtracking(int pos) {
	if (pos == n + 1) {
		cnt++;
		return ;
	}
	for (int j = 1; j <= n; j++) {
		flag = 0;
		for (int i = 1; i < pos; i++) {
			if (board[i] - pos + i == j) flag = 1;
			else if (board[i] + pos - i == j) flag = 1;
			else if (board[i] == j) flag = 1;
			if (flag) break ;
		}
		if (!flag) {
			board[pos] = j;
			ft_backtracking(pos + 1);
			board[pos] = 0;
		}
	}
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	ft_backtracking(1);
	cout << cnt;
	return (0);
}