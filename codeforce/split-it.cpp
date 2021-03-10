#include <iostream>
#include <cstring>

using namespace std;

string		str;
int			n, k, t;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--)
	{
		cin >> n >> k >> str;
		if (k == 0)
		{
			cout << "YES";
			if (t) cout << "\n";
			continue ;
		}
		if (2 * k + 1 > n)
		{
			cout << "NO";
			if (t) cout << "\n";
			continue ;
		}

		int	flag = 0;
		for (int i = 0; i < k; i++)
		{
			if (str[i] != str[n - 1 - i])
			{
				cout << "NO";
				if (t) cout << "\n";
				flag = 1;
				break ;
			}
		}
		if (flag == 1)
			continue;
		cout << "YES";
		if (t) cout << "\n";
	}

	
	return (0);
}
