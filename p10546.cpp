#include <iostream>
#include <string>
#include <map>
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

	int					n;
	string				s;
	map<string, int>	mp;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		mp[s]++;
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> s;
		if (mp[s]) mp[s]--;
	}
	for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		if (it->second) {
			cout << it->first;
			break ;
		}
//		cout << "first : " << it->first << " second : " << it->second << "\n";
	}
	return (0);
}
