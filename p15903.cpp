#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	unsigned long long			n, m, a, ans = 0;
	vector<unsigned long long>	v;

	cin >> n >> m;
	while (n--) {
		cin >> a;
		v.push_back(a);
		ans += a;
	}
	while (m--) {
		sort(v.begin(), v.end());
		ans += v[0]; ans += v[1];
		n = v[0];								//	n is tmp
		v[0] += v[1];
		v[1] += n;
	}
	cout << ans;
	return (0);
}