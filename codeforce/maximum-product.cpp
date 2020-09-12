#include <iostream>
#include <vector>
//#include <queue>
//#include <stack>
//#include <list>
#include <algorithm>
#include <stdlib.h>

using namespace std;

bool		ft_sort(int i, int j)
{
	return (abs(i) > abs(j));
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			t, n, cnt, i, j, k, l, m, neg, pos;
	long long		a;
	vector<long long>		v;

	cin >> t;
	while (t--) {
		cin >> n;
		cnt = 0;
		i = 0;
		j = 1;
		k = 2;
		l = 3;
		m = 4;
		v.clear();
		while (n--) {
			cin >> a;
			v.push_back(a);
		}
		if (v.size() == 5) {
			cout << v[i] * v[j] * v[k] * v[l] * v[m];
			if (t != 0) cout << "\n";
			continue ;
		}
		sort(v.begin(), v.end(), ft_sort);
		if (v[4] == 0) {
			cout << 0;
			if (t != 0) cout << "\n";
			continue ;
		}
		for (int q = 0; q < 5; q++) {
			if (v[q] < 0) {
				cnt++;
				neg = q;
			}
			else pos = q;
		}
		if (cnt % 2) {
			for (int i = 5; i < (int)(v.size()); i++) {
				if (v[i] > 0) 
		}
		cout << v[i] * v[j] * v[k] * v[l] * v[m];
		if (t != 0) cout << "\n";
	}
	return (0);
}
