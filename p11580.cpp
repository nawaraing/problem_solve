#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long				n, k, start, end;
	vector<int>				v;
	int						a;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	cin >> k;
	start = 0;
	end = n / k;
	while (n != end) {
		sort(v.begin() + start, v.begin() + end);
		start = end;
		end += n / k;
	}
	sort(v.begin() + start, v.begin() + end);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i != v.size() - 1) cout << " ";
	}
	return (0);
}