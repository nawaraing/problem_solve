#include <iostream>
#include <vector>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			n, m, num, tmp, a, b, parent[1000001], rank[1000001];

	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
		rank[i] = 1;
	}
	while (m--) {
		cin >> num >> a >> b;
		if (num == 0) {
			while (a != parent[a]) a = parent[a];
			while (b != parent[b]) b = parent[b];
			if (rank[a] > rank[b]) {
				tmp = a;
				a = b;
				b = tmp;
			}
			parent[a] = b;
			if (a == b) rank[b]++;
		}
		else {
			while (a != parent[a]) a = parent[a];
			while (b != parent[b]) b = parent[b];
			if (a == b) cout << "YES\n";
			else cout << "NO\n";
		}
//		for (int i = 0; i <= n; i++) cout << parent[i] << " ";
//		cout << "\n";
	}
	return (0);
}