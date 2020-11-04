#include <iostream>
#include <string>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <list>
//#include <algorithm>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int				t, n, idx;
	bool			flag;

	cin >> t;
	while (t--) {
		flag = 0;
		cin >> n;
		if (n == 1) {
			int		digit;
			cin >> digit;
			if (digit % 2) cout << 1;
			else cout << 2;
			if (t) cout << "\n";
			continue ;
		}
		string			digit;
		cin >> digit;
		if (n % 2) idx = 0; // odd digit
		else idx = 1;
//		cout << "idx : " << idx << "\n";
		for (int i = idx; i < (int)digit.size(); i += 2) {
//			cout << "i : " << i << "\n";
			if (idx && (digit[i] - '0') % 2 == 0) { // breach
				cout << 2;
				flag = 1;
				break ;
			}
			else if ((!idx) && (digit[i] - '0') % 2 == 1) { // raze
				cout << 1;
				flag = 1;
				break ;
			}
		}
		if (!flag) {
			if (idx) cout << 1;
			else cout << 2;
		}
		if (t) cout << "\n";
	}
	return (0);
}
