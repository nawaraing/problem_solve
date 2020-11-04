#include <iostream>
//#include <map>
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

	int				n, a;
	vector<int>		v;

	cin >> n;
	while (n--) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	cin >> n;
	while (n--) {
		cin >> a;
		cout << upper_bound(v.begin(), v.end(), a) - lower_bound(v.begin(), v.end(), a);
		if (n) cout << " ";
	}
	return (0);
}
