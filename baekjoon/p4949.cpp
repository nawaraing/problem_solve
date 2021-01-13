#include <iostream>
#include <string>
//#include <vector>
//#include <queue>
#include <stack>
//#include <list>
//#include <algorithm>

using namespace std;

int		main(void)
{
	string		s;
	stack<char>	sta;
	bool		flag;

	getline(cin, s);
	while (s != ".") {
		flag = 0;
		while (sta.size()) sta.pop();
		for (unsigned long i = 0; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == '[') sta.push(s[i]);
			else if (s[i] == ')') {
				if (!sta.size() || sta.top() != '(') {
					cout << "no\n";
					break ;
				}
				else sta.pop();
			}
			else if (s[i] == ']') {
				if (!sta.size() || sta.top() != '[') {
					cout << "no\n";
					break ;
				}
				else sta.pop();
			}
			if (i == s.length() - 1)
				flag = 1;
		}
		if (flag == 1) {
			if (!sta.size())
				cout << "yes\n";
			else cout << "no\n";
		}
		getline(cin, s);
	}
	return (0);
}
