#include <iostream>
#include <string>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string		s1, s2;
	int		diff, cnt, max = 0;

	cin >> s1; cin >> s2;

	diff = (int)(s2.length()) - (int)(s1.length());
	for (int i = 0; i <= diff; i++) {
		cnt = 0;
		for (int j = 0; j < (int)(s1.length()); j++)
			if (s1[j] == s2[i + j]) cnt++;
		if (max < cnt)
			max = cnt;
	}
	cout << (s1.length() - max);
	return (0);
}
