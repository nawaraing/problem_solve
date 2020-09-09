#include <iostream>
#include <string>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string		s;
	int		even = 0, ans =  0;

	for (int i = 0; i < 8; i++) {
		cin >> s;
		for (int j = 0; j < 4; j++)
			if (s[2 * j + even] == 'F') ans++;
		even = (even == 0) ? 1 : 0;
	}
	cout << ans;
	return (0);
}
