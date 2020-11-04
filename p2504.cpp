#include <iostream>
//#include <vector>
//#include <queue>
#include <stack>
#include <string>
//#include <list>
//#include <algorithm>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	stack<long long>			st;
	long long					n;
	string						s;
	bool						flag = 0;

	cin >> s;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == '(') st.push(-1);
		else if (s[i] == '[') st.push(-2);
		else if (!st.size()) {
			cout << "0";
			flag = 1;
			break ;
		}
		else {
			n = 1;
			if (st.top() >= 0) {
				n = st.top();
				st.pop();
			}
			if (!st.size() || ((st.top() == -1 && s[i] == ']') || (st.top() == -2 && s[i] == ')'))) {
				cout << "0";
				flag = 1;
				break ;
			}
			st.pop();
			if (s[i] == ')') n *= 2;
			else n *= 3;
			while (st.size() && st.top() >= 0) {
				n += st.top();
				st.pop();
			}
			st.push(n);
		}
	}
	if (!flag) {
		if (st.size() != 1) cout << "0";
		else cout << st.top();
	}
	return (0);
}
