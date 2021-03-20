#include <iostream>
#include <string>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string		rules[51];
	int			q, r;

	cin >> q;
	cin.ignore();
	for (int i = 1; i <= q; i++)
		getline(cin, rules[i]);
	cin >> r;
	while (r--)
	{
		int		a;
		cin >> a;
		if (a < 1 || a > q)
		{
			cout << "Rule " << a << ": No such rule";
		}
		else
		{
			cout << "Rule " << a << ": " << rules[a];
		}
		if (r) cout << "\n";
	}

	return (0);
}