#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <list>
#include <stdlib.h>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int								t, n, l, k, p, a;
	vector<pair<int, int> >			v;
	list<int>						lst;

	cin >> t;
	while (t--) {
		cin >> n >> l >> k;
		v.clear();
		lst.clear();
		for (int i = 0; i < n ; i++) {
			cin >> p >> a;
			if (a < 0) {
				v.push_back(make_pair(p, a));
			}
			else
				v.push_back(make_pair(l - p, a));
			lst.push_back(a);
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < k - 1; i++) {
			if (v[i].second > 0) lst.pop_back();
			else lst.pop_front();
		}
		if ((k > 1 && v[k - 2].first == v[k - 1].first)\
		 || (n > k && v[k - 1].first == v[k].first)) {
			if (lst.front() > lst.back()) a = lst.back();
			else a = lst.front();
		}
//		else if (v[k - 1].first == v[k].first) {
//			if (lst.front() > lst.back()) a = lst.back();
//			else a = lst.front();
//		}
		else
		{
			if (v[k - 1].second > 0) a = lst.back();
			else a = lst.front();
		}
		cout << a;
		if (t) cout << "\n";
	}
	return (0);
}