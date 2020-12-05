#include <iostream>
#include <vector>

using namespace std;

vector<int>	v;			// card set

bool	ft_has_card(int a) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == a) return (true);
	}
	return (false);
}

int		ft_dfs(int a) {
	int			tmp = a;
	bool		flag = 0;
	int			val;
	int			minn;

	while (tmp) {
		if (!ft_has_card(tmp % 10)) {
			flag = 1;
			break ;
		}
		tmp /= 10;
	}
	if (!flag) return (0);
	minn = 2147483647;
	for (int i = 2; i <= a / i; i++) {
		if (a % i) continue ;
		if (ft_dfs(a / i) == -1 || ft_dfs(i) == -1) continue ;
		val = ft_dfs(a / i) + ft_dfs(i) + 1;
		if (minn > val) minn = val;
	}
	if (minn == 2147483647) return (-1);
	return (minn);
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			t, n, m, a;

	cin >> t;
	while (t--) {
		cin >> n;
		v.clear();
		while (n--) {
			cin >> a;
			v.push_back(a);
		}
		cin >> m;
		while (m--) {
			cin >> a;
			cout << ft_dfs(a) << "\n";
		}
	}
	return (0);
}