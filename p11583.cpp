#include <iostream>
#include <utility>
#include <limits.h>

using namespace std;

int				t, n, k, a, f, s, minn;
int				stone_two[100000], sum_two[100000], stone_five[100000], sum_five[100000];			//		< 2, 5 >

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> a;
			stone_two[i] = stone_five[i] = sum_two[i] = sum_five[i] = 0;
			while (!(a % 2)) {
				stone_two[i]++;
				a /= 2;
			}
			while (!(a % 5)) {
				stone_five[i]++;
				a /= 5;
			}
			sum_two[i] = INT_MAX;
			sum_five[i] = INT_MAX;
		}
//				for (int i = 0;i < n; i++) cout << sum_two[i].first << " " << sum_two[i].second << "\n\n";
		sum_two[0] = stone_two[0];
		sum_five[0] = stone_five[0];
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j <= i + k; j++) {
				if (j >= n) break ;
				if (sum_two[i] + stone_two[j] < sum_two[j]) sum_two[j] = sum_two[i] + stone_two[j];
				if (sum_five[i] + stone_five[j] < sum_five[j]) sum_five[j] = sum_five[i] + stone_five[j];
			}
		}
		for (int i = 0;i < n; i++) cout << sum_two[i] << " " << sum_five[i] << "\n";
		if (sum_two[n - 1] < sum_five[n - 1]) cout << sum_two[n - 1];
		else cout << sum_five[n - 1];
		if (t) cout << "\n";
	}
	return (0);
}