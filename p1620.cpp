#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <list>
//#include <algorithm>
#include <string>
#include <map>

using namespace std;


int		ft_atoi(string s)
{
	int			n = 0;

	for (int i = 0; i < (int)s.length(); i++) {
		n = n * 10 + s[i] - '0';
	}
	return n;
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int				n, m;
	string			s;
	map<string, int>		mp;

	cin >> n >> m;
	string			strs[n + 1];

	for (int i = 1; i < n + 1; i++) {
		cin >> s;
		strs[i] = s;
		mp[s] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (s[0] >= '1' && s[0] <= '9') {
			int			num = ft_atoi(s);
			cout << strs[num];
		}
		else cout << mp[s];
		if (i != m) cout << '\n';
	}
	return (0);
}
