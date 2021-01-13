#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		a, b;

	cin >> a >> b;
	if (a - b > 0) cout << ">";
	else if (a - b < 0) cout << "<";
	else cout << "==";
	return (0);
}