#include <iostream>
#include <queue>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		t, n, tmp, even, odd, cnt;
	queue<int>	q, ans;

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			q.push(tmp);
		}
		while (1) {
			if (q.size() == 0) break;
			odd = q.front();
			q.pop();
			if (q.size() == 0) break;
			even = q.front();
			q.pop();
			if (odd == even) {
				ans.push(odd); ans.push(odd);
			}
			else
			{
				if (q.size() == 0) {
					ans.push(0);
					break ;
				}
				tmp = q.front();
				q.pop();
				ans.push(tmp); ans.push(tmp);
			}
		}
		cout << ans.size() << "\n";
		while (1) {
			cout << ans.front();
			ans.pop();
			if (ans.size() != 0) cout << " ";
			else break;
		}
		if (t != 0) cout << "\n";
	}
	return (0);
}
