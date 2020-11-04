#include <iostream>
#include <vector>
//#include <queue>
//#include <stack>
//#include <list>
#include <algorithm>

using namespace std;

typedef long long ll;

bool	ft_sort(ll i, ll j) {return i < j;}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll			n, a, tmp;
	vector<ll>			v;

	cin >> n;
	for (ll i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end(), ft_sort);
/*
	for (int i = 0; i < (int)v.size(); i++) {
		cout << v[i];
		if (i != v.size() - 1) cout << " ";
	}
*/
	if (n < 3) {
		cout << "0\n";
		for (int i = 0; i < (int)v.size(); i++) {
			cout << v[i];
			if (i != (int)v.size() - 1) cout << " ";
		}
		return (0);
	}
	for (int i = 0; i < (int)v.size() - 1; i += 2) {
		tmp = v[i];
		v[i] = v[i + 1];
		v[i + 1] = tmp;
	}
	cout << n / 2 << "\n";
	for (int i = 0; i < (int)v.size(); i++) {
		cout << v[i];
		if (i != v.size() - 1) cout << " ";
	}
	return (0);
}
