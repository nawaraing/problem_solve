#include <iostream>
#include <string>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string		s;
	int			t;

	cin >> t;
	while (t--)
	{
		cin >> s;
		int	len = s.length();
		int	idx = -1;

		for (int i = 0; i < len; i++)
		{
			if (s[i] != 'a')
			{
				idx = i;
				break ;
			}
		}
		if (idx == -1)
			cout << "NO";
		else
		{
			cout << "YES" << endl;
			s.insert(len - idx, "a");
			cout << s;
		}
		if (t) cout << endl;
	}

	return (0);
}
