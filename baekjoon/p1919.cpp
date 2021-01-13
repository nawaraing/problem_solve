#include <iostream>
#include <string>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string		s1, s2;
	int		len;
	cin >> s1;
	cin >> s2;
	len = s1.length() + s2.length();
	for (int i = 0; i < s1.length(); i++) {
		for (int j = 0; j < s2.length(); j++) {
			if (s1[i] == s2[j]) {
				s2[j] = 0;
				len -= 2;
				break ;
			}
		}
	}
	cout << len;
	return (0);
}
