#include <iostream>
#include <vector>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			a, b, m, sum = 0, tmp;
	vector<int>	v;

	cin >> a >> b >> m;
	while (m--) { 
		cin >> tmp;
		sum *= a;
		sum += tmp;
	}
	while (sum) {
		v.push_back(sum % b);
		sum /= b;
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i];
		if (i != 0) cout << " ";
	}
	return (0);
}