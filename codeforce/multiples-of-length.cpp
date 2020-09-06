#include <iostream>
#include <vector>

using namespace std;

int			main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			n, a;
	vector<int>		v;

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a;
		v.push_back(a);
	}
	cout << "1 1\n-1\n1 1\n-1\n";
	cout << "1 " << n << "\n";
	for (int i = 0; i < n; i++) {
		if (i == 0) cout << (-1) * (v[i] - 2) << " ";
		else if (i == n - 1) cout << (-1) * v[i];
		else cout << (-1) * v[i] << " ";
	}
	return (0);
}
		
