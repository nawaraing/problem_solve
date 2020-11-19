#include <iostream>

using namespace std;

#define FULL 1048575

int				train[100001];
bool			flag;

class	seat {
	public:

	int		ft_seat(int x) {
		int		ret = 1;

		return (ret << (x - 1));
	}

	void	ft_add(int i, int x) {
		x = ft_seat(x);
		train[i] |= x;
		return ;
	}

	void	ft_remove(int i, int x) {
		x = ft_seat(x);
		train[i] &= (FULL - x);
		return ;
	}

	void	ft_left(int i) {
		train[i] <<= 1;
		train[i] &= FULL;
		return ;
	}

	void	ft_right(int i) {
		train[i] >>= 1;
		return ;
	}
};

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		n, m, command, i, x, cnt = 0;
	seat	sseat;

	cin >> n >> m;
	while (m--) {
		cin >> command >> i;
		if (command == 1) {
			cin >> x;
			sseat.ft_add(i, x);
		}
		else if (command == 2) {
			cin >> x;
			sseat.ft_remove(i, x);
		}
		else if (command == 3) {
			sseat.ft_left(i);
		}
		else if (command == 4) {
			sseat.ft_right(i);
		}
		else cout << "wrong\n";
	}
	for (int i = 1; i <= n; i++) {
		flag = 0;
		for (int j = 1; j < i; j++) {
			if (train[j] == train[i]) {
				flag = 1;
				break ;
			}
		}
		if (!flag) cnt++;
	}
	cout << cnt;
	return (0);
}