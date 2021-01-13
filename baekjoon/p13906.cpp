#include <iostream>
#include <string>

using namespace std;


int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string		s;
	int			dp[1001];

	for (int i =0; i <= 1000; i++)
		dp[i] = 1;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		int		alpha[26] = {0};
		for (int j = i; j >= 0; j--)
		{
			if (++alpha[s[j] - 'a'] == 3) {
				if (j != 0)
					dp[i] += dp[j - 1];
				else dp[i] += 1;
				dp[i] %= 1000000007;
			}
		}
	}
	cout << dp[s.size() - 1] - 1;
	return (0);
}