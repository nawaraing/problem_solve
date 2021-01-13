#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			t, m, num;
	char		c, alpha;

	cin >> t;
	while (t--) {
		cin >> m >> c;
		while (m--) {
			if (c == 'C') {
				cin >> alpha;
				cout << (int)(alpha - 'A' + 1) << " ";
			}
			else {
				cin >> num;
				cout << (char)(num + 'A' - 1) << " ";
			}
		}
		cout << "\n";
	}
	return (0);
}