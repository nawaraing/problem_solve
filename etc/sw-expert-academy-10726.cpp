#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <list>
//#include <algorithm>
#include <cmath>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			tc, n, m;

	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		n = pow(2, n);
		m -= n;
		m++;
		if (m % n) cout << "OFF";
		else cout << "ON";
		if (tc) cout << "\n";
	}

	return (0);
}
