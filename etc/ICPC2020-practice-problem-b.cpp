#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			n, a, b, suma = 0, sumb = 0;

	cin >> n;
	while (n--) {
		cin >> a >> b;
		if (suma + a > sumb + b) {
			sumb += b;
		}
		else if (suma + a < sumb + b) {
			suma += a;
		}
		else if (a > b) {
			sumb += b;
		}
		else {
			suma += a;
		}
	}
	if (suma < sumb) {
		cout << sumb;
	}
	else cout << suma;
	return (0);
}
