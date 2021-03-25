#include <iostream>
#include <string>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	int		t;
	
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		int		ans = 0;
		for (int i = 0; i < a.length(); i++)
		{
			for (int j = 1; j <= a.length() - i; j++)
			{
				if (b.find(a.substr(i, j)) != string::npos)
				{
					if (ans < j)
						ans = j;
				}
			}
		}
		cout << a.length() + b.length() - 2 * ans;
		if (t) cout << endl;
	}

	return (0);
}
