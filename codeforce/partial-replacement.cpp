#include <iostream>
#include <string>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		t, n, k;
	string	s;

	cin >> t;
	while (t--){
		cin >> n >> k >> s;
		int		last_idx = -1;
		int		before_idx = -1;
		int		is_start = 0;
		int		ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '*')
			{
				if (is_start == 0)
				{
					is_start = 1;
					before_idx = i;
					ans++;
					s[i] = 'x';
				}
				else {
					if (i - before_idx > k)
					{
						if (s[last_idx] == '*')
						{
							s[last_idx] = 'x';
							before_idx = last_idx;
							ans++;
						}
					}
				}
				last_idx = i;
			}
		}
		if (s[last_idx] == '*')
			ans++;
		cout << ans;
		if (t) cout << endl;
	}

	return (0);
}
