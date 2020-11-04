#include <iostream>
#include <set>
//#include <queue>
//#include <stack>
//#include <list>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int					t, n, a;
	set<int>			s;
	
	cin >> t;
	while (t--) {
		cin >> n;
		while (n--) {
			cin >> a;
			s.insert(a);
		}
		cin >> n;
		while (n--) {
			cin >> a;
			if (s.end() != s.find(a)) cout << "1";
			else cout << "0";
			if (n) cout << "\n";
		}
	}
	return (0);
}
