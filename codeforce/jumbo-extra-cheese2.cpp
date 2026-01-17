#include <iostream>

using namespace std;


int		main(void)
{
	long long t, n, a, b, mins = 0, maxi = 0, tmp;

	cin >> t;
	for (int i = 0; i < t; i++) {
		mins = 0;
		maxi = 0;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> a >> b;
			if (a < b) {
				tmp = b;
				b = a;
				a = tmp;
			}

			mins += b;
			if (maxi < a) maxi = a;
		}
		cout << 2*(mins+maxi) << "\n";
	}
}
