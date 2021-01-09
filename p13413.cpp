#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			n, t, diff = 0, b_diff = 0, one = 0, two = 0;
	string		s1, s2;
	int			ans = 0;

	cin >> t;
	while (t--)
	{
		diff = 0;
		b_diff = 0;
		one = 0;
		two = 0;
		cin >> n;
		cin >> s1 >> s2;
		for (int i = 0; i < n; i++)
		{
			if (s1[i] != s2[i]) diff++;
			if (s1[i] == 'B') one++;
			if (s2[i] == 'B') two++;
		}
		b_diff = abs(one - two);
		ans = b_diff;
		ans += (diff - b_diff) / 2;
		cout << ans;
		if (t) cout << "\n";
	}
	return (0);
}