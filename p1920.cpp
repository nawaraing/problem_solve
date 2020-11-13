#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>	v;
int			n, m, a;

int		ft_binary_search(int s, int e, int data) {
	int		mid;
	int		ret;

	if (s >= e) return (0);
	mid = (s + e) / 2;
	if (v[mid] == data) return (1);
	else if (s + 1 == e) {
		if (v[mid + 1] == data) return (1);
		return (0);
	}
	else if (v[mid] > data) ret = ft_binary_search(s, mid, data);
	else ret = ft_binary_search(mid, e, data);
	return (ret);
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a;
		cout << ft_binary_search(0, n - 1, a);
		if (i != m) cout << "\n";
	}
	return (0);
}