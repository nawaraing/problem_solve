#include <iostream>
//#include <vector>
#include <queue>
//#include <stack>
//#include <list>
//#include <algorithm>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			n, k;
	queue<int>		q;

	cin >> n; cin >> k;
	for (int i = 1; i < n + 1; i++) q.push(i);
	cout << "<";
	while (q.size()) {
		for (int i = 0; i < k - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();
		if (q.size()) cout << ", ";
	}
	cout << ">";
	return (0);
}
