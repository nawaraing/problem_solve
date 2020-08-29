#include <iostream>
#include <vector>

using namespace std;

int			main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		n, a = 0, ans = 0;
	vector<int>	left, right;

	left.push_back(a);
	right.push_back(a);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		left.push_back(left.back() + (a * a));
		right.push_back(right.back() + a);
	}
	for (int i = 0; i <= n; i++) {
		if (ans < (left[i] * (right[n] - right[i])))
			ans = left[i] * (right[n] - right[i]);
	}
	cout << ans;
	return (0);
}
