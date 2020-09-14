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
	getline(cin, s);
	while (s != ".") {
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
				if (!sta.size() || sta.top() != '(') {
					cout << "no\n";
					break ;
				}
				else sta.pop();
			}
		}
		if (!sta.size()) {
			cout << "no\n";
			continue ;
		}
		cout << "yes\n";
		getline(cin, s);
	}
	return (0);
}
