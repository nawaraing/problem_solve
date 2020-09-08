#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		t, sum, tmp;

	cin >> t;
	while (t--) {
		cin >> sum;
		cin >> tmp;
		sum += tmp;
		cout << sum;
		if (t != 0) cout << "\n";
	}
	return (0);
}
