#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	unsigned long long	t, a, b, x, y, n;
	unsigned long long	min, aa, bb;

	cin >> t;
	while (t--) {
		cin >> a;
		cin >> b;
		cin >> x;
		cin >> y;
		cin >> n;
		min = -1;

		if (a - x + b - y <= n) {
			aa = x;
			bb = y;
		}
		else if (a - x >= n) {
			aa = a - n;
			bb = b;
		}
		else {
			aa = x;
			bb = b - n + a - x;
		}
		cout << "aa : " << aa << "   bb : " << bb << "   min : " << min << "\n";
		min = aa * bb;
		while (aa < a && bb > y) {
			aa++;
			bb--;
			if (aa * bb <= min) min = aa * bb;
			else break ;
		}
		cout << "aa : " << aa << "   bb : " << bb << "   min : " << min << "\n"; 
		cout << min;
		if (t != 0) cout << "\n";
	}
	return (0);
}
