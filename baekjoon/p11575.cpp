#include <iostream>
#include <cstring>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			t, a, b;
	string		str;

	cin >> t;
	while (t--) {
		cin >> a >> b >> str;
		for (int i = 0; i < str.size(); i++) {
			str[i] = 'A' + (a * (str[i] - 'A') + b) % 26;
		}
		cout << str;
		if (t) cout << "\n";
	}
	return (0);
}