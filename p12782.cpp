#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		t, acnt = 0, bcnt = 0, res, cnt;
	string			s1, s2;

	cin >> t;
	while (t--) {
		cin >> s1 >> s2;
		res = 0;
		acnt = 0;
		bcnt = 0;
		cnt = 0;
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] == '1') acnt++;
			if (s2[i] == '1') bcnt++;
			if (s1[i] != s2[i]) cnt++;
		}
		res = abs(acnt - bcnt);
		cnt -= res;
		cnt /= 2;
		res += cnt;
		cout << res << "\n";
	}
	return (0);
}