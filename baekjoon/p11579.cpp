#include <iostream>
#include <vector>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int				t, n, a, mov[500][500], pos[500], sum[500];
	vector<int>		v;
	
	cin >> t;
	while (t--) {
		cin >> n;
		int	ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> mov[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			cin >> pos[i];
		}
//		if (pos[0] < 0) {
//			cout << 0;
//			if (t) cout << " ";
//			continue ;
//		}
		for (int i = 0; i < n; i++) sum[i] = 0;
		bool			flag = 0;
		for (int i = 0; i < n; i++) {
			if (pos[i] == sum[i]) continue ;
			a = pos[i] - sum[i];
			if (a < 0) {
				cout << 0;
				if (t) cout << "\n";
				flag = 1;
				break ;
			}
			ans += a;
			for (int j = i; j < n; j++) {
				sum[j] += mov[i][j] * a;
			}
		}
		if (flag) continue ;
		cout << 1 << " " << ans;
		if (t) cout << "\n";
	}
	return (0);
}