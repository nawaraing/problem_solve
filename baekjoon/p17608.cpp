#include <iostream>
#include <stack>

using namespace std;

int		n, h, maxi = 0, ans = 0;
stack<int> st;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h;
		st.push(h);
	}
	while (!st.empty()) {
		h = st.top();
		st.pop();
		if (maxi >= h) {
			continue;
		}
		// cout << "h: " << h << "\n"; 
		maxi = h;
		ans++;
	}
	cout << ans;
}