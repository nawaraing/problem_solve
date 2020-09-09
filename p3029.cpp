#include <iostream>
#include <string>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string		str1, str2;
	int		h, m, s, total;
	int		h2, m2, s2, total2;

	cin >> str1; cin >> str2;
	h = (str1[0] - '0') * 10 + (str1[1] - '0');
	m = (str1[3] - '0') * 10 + (str1[4] - '0');
	s = (str1[6] - '0') * 10 + (str1[7] - '0');
	total = h * 3600 + m * 60 + s;
	h2 = (str2[0] - '0') * 10 + (str2[1] - '0');
	m2 = (str2[3] - '0') * 10 + (str2[4] - '0');
	s2 = (str2[6] - '0') * 10 + (str2[7] - '0');
	total2 = h2 * 3600 + m2 * 60 + s2;
	total -= total2;
	if (total > 0)
		total = 86400 - total;
	h = total / 3600;
	total %= 3600;
	m = total / 60;
	total %= 60;
	s = total;
	if (h < 10) cout << 0;
	cout << h << ":";
	if ( m < 10) cout <<0;
	cout << m <<":";
	if (s < 10) cout << 0;
	cout << s;
	return (0);
}
