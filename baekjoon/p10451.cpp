#include <iostream>
#include <vector>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			t, n, a;

	cin >> t;
	while (t--) {
		vector<int>		per;
		vector<int>		set;	
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a;
			per.push_back(a);
			set.push_back(i + 1);
		}
		int				cnt = 0;
		for (int i = 0; i < n; i++) {
			if (set[i] != i + 1) continue ;
			int		tmp = i;
			while (set[per[i] - 1] != set[i]) {
				set[per[i] - 1] = set[i];
				i = per[i] - 1;
			}
			i = tmp;
			cnt++;
		}
		cout << cnt;
		if (t) cout << "\n";
	}
	return (0);
}