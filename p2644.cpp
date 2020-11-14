#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int				visit[101];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int				n, a, b, begin, end, m;
	vector<int>					v[101];
	queue<pair<int, int> >		q;
	pair<int, int>				pr;

	cin >> n;
	cin >> begin >> end;
	cin >> m;
	while (m--) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	q.push(make_pair(begin, 0));
	while (q.size()) {
		pr = q.front();
		q.pop();
		if (pr.first == end) break ;
		for (int i = 0; i < (int)v[pr.first].size(); i++) {
			if (!visit[v[pr.first][i]]) {
				visit[v[pr.first][i]] = 1;
				q.push(make_pair(v[pr.first][i], pr.second + 1));
			}
		}
	}
	if (pr.first == end) cout << pr.second;
	else cout << -1;
	return (0);
}