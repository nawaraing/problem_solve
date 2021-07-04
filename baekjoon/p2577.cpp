#include <iostream>

using namespace std;

int		cnts[10];
int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		a, b, c;

	cin >> a >> b >> c;
	a *= b * c;
	while (a)
	{
		cnts[a % 10]++;
		a /= 10;
	}
	for (int i = 0; i < 10; i++)
		cout << cnts[i] << "\n";
	return (0);
}
