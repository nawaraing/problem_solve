#include <iostream>
#include <string>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string		str;
	int			pos = 0, neg = 0;
	
	getline(cin, str);
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ':' && str[i + 1] == '-')
		{
			if (i < str.length() - 3)
			{
				if (str[i + 2] == ')') pos++;
				else if (str[i + 2] == '(') neg++;
			}
		}
	}
	if (pos == 0 && neg == 0)
		cout << "none";
	else if (pos == neg)
		cout << "unsure";
	else if (pos > neg)
		cout << "happy";
	else cout << "sad";
	return (0);
}