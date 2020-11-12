#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int							v[100000];
	int							n, a, b, x;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v[i] = a;
	}
	cin >> x;
	sort(v, v + n);
	a = 0;
	b = n - 1;
	n = 0;
	while (a < b) {
		if (v[a] + v[b] > x) b--;
		else if (v[a] + v[b] < x) a++;
		else {
			n++;
			a++;
		}
	}
	cout << n;
	return (0);
}