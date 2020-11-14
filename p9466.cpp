#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int				visit[100001];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			t, n, a, cnt = 0;
	vector<int>	tot, use;							// tot : 전체 수열을 받아옴
	queue<int>	q;									// use : 이번에 꼬리물기를 하는 번호들을 차례로 저장
													// queue가 필요가 없는 듯..

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) visit[i] = 0;
		tot.clear();
		for (int i = 0; i < n; i++) {
			cin >> a;
			tot.push_back(a);
		}
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (visit[i]) continue ;
			while (q.size()) q.pop();
			q.push(i);
			use.clear();
			while (q.size()) {
				a = q.front();
				q.pop();
				visit[a] = 1;
				use.push_back(a);
				if (!visit[tot[a - 1]]) q.push(tot[a - 1]);
				else {
					for (int j = 0; j < use.size(); j++) {
						if (use[j] == tot[a - 1]) break ;
						cnt++;
					}
				}
			}
		}
		cout << cnt;
		if (t) cout << "\n";
	}
	return (0);
}