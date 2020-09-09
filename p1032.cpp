#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			n;
	string			s;
	vector<string>		v;
	list<int>		l;
	char			c;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	for (int i = 0; i < (int)(v[0].length()); i++) {
		c = v[0][i];
		for (int j = 1; j < (int)(v.size()); j++) {
			if (v[j][i] != c) break ;
			if (j == (int)(v.size()) - 1) l.push_back(i);
		}
	}
	l.push_back((int)(v[0].length()));
	n = -1;
	while (l.size()) {
		for (int i = 1; i < l.front() - n; i++) cout << "?";
		if (l.size() == 1) break ;
		n = l.front();
		cout << v[0][l.front()];
		l.pop_front();
	}
	return (0);
}
