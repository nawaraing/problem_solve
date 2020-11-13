#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int					n, a, g_cnt = 0, h_cnt = 0, maxi = 0;
	char				c;
	vector<pair<int, char> >			v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> c;
		v.push_back(make_pair(a, c));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		if (v[n - 1].first - v[i].first <= maxi) break ;
		g_cnt = 0;
		h_cnt = 0;
		for (int j = i; j < n; j++) {
			if (v[j].second == 'G') g_cnt++;
			else h_cnt++;
			if (h_cnt == 0 || g_cnt == 0 || h_cnt == g_cnt) {
				if (v[j].first - v[i].first > maxi)
					maxi = v[j].first - v[i].first;
			}
		}
	}
	cout << maxi;
	return (0);
}