#include <iostream>
#include <stack>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int					n, k, coin, ans = 0;
	stack<int>			st;

	cin >> n >> k;
	while (n--) {
		cin >> coin;
		st.push(coin);
	}
	while (st.size()){
		coin = st.top();
		st.pop();
		if (coin > k) continue ;
		while (coin <= k) {
			k -= coin;
			ans++;
		}
		if (!k) break ;
	}
	cout << ans;
	return (0);
}