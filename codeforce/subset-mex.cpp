#include <iostream>
#include <vector>
//#include <queue>
//#include <stack>
//#include <list>
#include <algorithm>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		t, n, a;
	vector<int>	v, t1, t2;

	cin >> t;
	while (t--) {
		v.clear();
		t1.clear();
		t1.push_back(-1);
		t2.clear();
		t2.push_back(-1);
		cin >> n;
		while (n--) {
			cin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		while (v.size()) {
			if (t1.back() == v.front() - 1) t1.push_back(v.front());
			else if (t2.back() == v.front() - 1) t2.push_back(v.front());
			else if (v.front() == t2.back()) t2.push_back(v.front());
			else if (v.front() == t1.back()) t1.push_back(v.front());
			else break ;
			v.erase(v.begin());
		}
		cout << t1.back() + t2.back() + 2;
		if (t != 0) cout << "\n";
	}
	return (0);
}
