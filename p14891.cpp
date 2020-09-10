#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	list<int>		a1, a2, a3, a4;
	int			k, tmp;
	string			s;
	vertor<int>		v;

	cin >> s;
	for (int i = 0; i < 8; i++) {
		if (s[i] == '0') a1.push_back(0);
		else a1.push_back(1);
	}
	cin >> s;
	for (int i = 0; i < 8; i++) {
		if (s[i] == '0') a2.push_back(0);
		else a2.push_back(1);
	}
	cin >> s;
	for (int i = 0; i < 8; i++) {
		if (s[i] == '0') a3.push_back(0);
		else a3.push_back(1);
	}
	cin >> s;
	for (int i = 0; i < 8; i++) {
		if (s[i] == '0') a4.push_back(0);
		else a4.push_back(1);
	}
	cin >> k;
	while (k--) {
		
	return (0);
}
