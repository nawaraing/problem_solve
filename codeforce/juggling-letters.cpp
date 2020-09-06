#include <iostream>
#include <cstring>

using namespace std;

int			main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		t, n, alpha[26];
	string		str;

	cin >> t;
	while (t--) {
		memset(alpha, 0, sizeof alpha);
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> str;
			for (int i = 0; i < str.length(); i++) alpha[(int)(str[i] - 'a')]++;
		}
		for (int i = 0; i < 26; i++) {
			if (alpha[i] % n != 0) {
				cout << "NO\n";
				break ;
			}
			else if (i == 25) cout << "YES\n";
		}
	}
	return (0);
}				
