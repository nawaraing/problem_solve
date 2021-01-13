#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		n;

	cin >> n;
	for (int i = n; i > 0; i--) {
		for (int j = i; j > 0; j--)
			cout << "*";
		if (i != 1) cout << "\n";
	}
	return (0);
}
