#include <iostream>

using namespace std;

bool		a[33554433];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		b;
	bool	flag = 0;

	while (!cin.eof()) {
		cin >> b;
		if (!a[b]) {
			a[b] |= 1;
			if (flag) cout << " ";
			cout << b;
		}
		flag = 1;
	}
	return (0);
}