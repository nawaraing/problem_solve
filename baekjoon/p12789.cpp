#include <iostream>
//#include <vector>
#include <queue>
#include <stack>
//#include <list>
//#include <algorithm>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			n, a;
	queue<int>		q;
	stack<int>		st;
	bool			flag = 1;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		q.push(a);
	}
	for (int i = 1; i < n + 1; i++) {
		if (q.size() && i == q.front()) {
			q.pop();
			continue ;
		}
		else if (st.size() && i == st.top()) {
			st.pop();
			continue ;
		}
		else {
			while (q.size()) {
				st.push(q.front());
				q.pop();
				if (q.front() == i) {
					q.pop();
					break ;
				}
			}
		}
		if (!q.size() && (st.top() != i + 1 || st.size() != n - i)) {
			flag = 0;
			cout << "Sad";
			break ;
		}
	}
	if (flag == 1) cout << "Nice";
	return (0);
}
