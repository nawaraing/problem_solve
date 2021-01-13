#include <iostream>
#include <string>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			n;
	string		ans;
	string		str;

	cin >> n;
	cin >> ans;
	n -= 1;
	while (n--)
	{
		cin >> str;
		for (int i = 0; i < str.size(); i++)
		{
			if (ans[i] == '?' || ans[i] == str[i])
				continue ;
			ans[i] = '?';
		}
	}
	cout << ans;
}
