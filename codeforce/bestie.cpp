#include <iostream>

using namespace std;

int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}

int		main(void)
{
	int t, n, a=0, b, flag = 0;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		a = 0;
		flag = 0;
		for (int j = 0; j < n; j++) {
			cin >> b;
			if (a == 0) {
				a = b;
			} else {
				a = gcd(a, b);
			}
		}
		if (a == 1){
			cout << 0 << "\n";
		} else  {
			if (gcd(a, n) == 1){
				cout << 1 << "\n";
			} else if (gcd(a, n - 1) == 1) {
				cout << 2 << "\n";
			} else {
				cout << 3 << "\n";
			}
		}
	}
}
