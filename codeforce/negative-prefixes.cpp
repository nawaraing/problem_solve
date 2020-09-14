#include <iostream>
#include <vector>
//#include <queue>
//#include <stack>
//#include <list>
#include <algorithm>


using namespace std;

bool		 myfunction (int i,int j) { return (i < j); }

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int>			v, un, neg_val;
	int				t, n, a;

	cin >> t;
	while (t--) {
		un.clear();
		neg_val.clear();
		v.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a;
			v.push_back(a);
		}
		for (int i = 0; i < n; i++) {
			cin >> a;
			if (a == 0)
				un.push_back(i);
		}
		if (un.size() <= 1) {
			for (int i = 0; i < n; i++) {
				cout << v[i];
				if (i != n - 1) cout << " ";
			}
			if (t != 0) cout << "\n";
			continue ;
		}
		for (unsigned long i = 0; i < un.size(); i++) {
			neg_val.push_back(v[un[i]]);
		}
		sort(neg_val.begin(), neg_val.end(), myfunction);
		for (unsigned long i = 0; i < un.size(); i++) {
			v[un[i]] = neg_val.back();
			neg_val.pop_back();
		}
		for (int i = 0; i < n; i++) {
			cout << v[i];
			if (i != n - 1) cout << " ";
		}
		if (t != 0) cout << "\n";
	}
	return (0);
}
