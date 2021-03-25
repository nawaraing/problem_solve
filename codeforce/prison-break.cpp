#include <iostream>

using namespace std;

int			t, a, b;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--)
	{
		cin >> a>> b;
		cout << a * b;
		if (t) cout << "\n";
	}
	return (0);
}
