#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int>			map[10001];
int					val[10001], rece[10001];
bool				visit[10001];
queue<int>			q;


int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			n, m, a, b;

	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		map[a].push_back(b);
		rece[b]++;
	}
	for (int i = 1; i <= n; i++) {
		if (rece[i] == 0) {
			val[i] = 1;
			q.push(i);
		}
	}
	b = 0;														//		save maxi, maxi cnt
	while (q.size()) {
		a = q.front();
		q.pop();
		visit[a] = 1;
		for (int i = 0; i < (int)map[a].size(); i++) {
			if (visit[map[a][i]]) continue ;
			if (val[map[a][i]] < val[a] + 1) {
				val[map[a][i]] = val[a] + 1;
				if (val[map[a][i]] > b) {
					b = val[map[a][i]];
				}
			}
			if (!--rece[map[a][i]]) q.push(map[a][i]);
		}
	}
//	cout << "val : ";
//	for (int i = 1; i <= n; i++) cout << val[i] << " ";
//	cout << "\n";
	for (int i = 1; i <= n; i++)
		if (val[i] == b) cout << i << " ";
	cout << "\b";
	return (0);
}