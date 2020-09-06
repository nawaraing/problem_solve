#include <iostream>
#include <stack>

using namespace std;

int		main(void)
{
	int		t, n, num;
	stack<int>	st;

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> num;
			st.push(num);
		}
		for (int i = 0; i < n; i++) {
			cout << st.top();
			st.pop();
			if (!st.empty())
				cout << " ";
		}
		if (t != 0) cout << "\n";
	}
	return (0);
}
