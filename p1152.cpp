#include <iostream>
#include <string>

using namespace std;

int		main(void)
{
	string		s;
	int		ans = 0;

	getline(cin, s);
	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i] != ' ' && s[i + 1] == ' ') ans++;
		else if (i + 1 == s.length() - 1 && s[i + 1] != ' ') ans++;
	}
	cout << ans;
	return (0);
}
