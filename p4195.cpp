#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int					t, f, a, b, tmp, cnt = 0;
	int					parent[200000], sums[200000];
	map<string, int>	users;
	string				name1, name2;

	cin >> t;
	while (t--) {
		cin >> f;
		users.clear();
		cnt = 0;
		for (int i = 0; i < 2 * f; i++) {
			parent[i] = i;
			sums[i] = 1;
		}
		while (f--) {
			cin >> name1 >> name2;
			a = -1;
			b = -1;
			if (users.find(name1) != users.end()) {
				a = users[name1];
			}
			if (users.find(name2) != users.end()) {
				b = users[name2];
			}
			if (a == -1 && b == -1) {
				users[name1] = cnt++;
				users[name2] = cnt++;
				a = users[name1];
				b = users[name2];
			}
			else if (a == -1 || b == -1) {
				if (a == -1) {
					users[name1] = cnt++;
					a = users[name1];
				}
				else {
					users[name2] = cnt++;
					b = users[name2];
				}
			}
			while (a != parent[a]) a = parent[a];
			while (b != parent[b]) b = parent[b];
//			cout << "a : " << a << " b : " << b << "\n";
			if (a == b) cout << sums[a] << "\n";
			else {
				parent[a] = b;
				sums[b] += sums[a];
				cout << sums[b] << "\n";
			}
//			cout << "sums\n";
//			for (int i = 0 ; i < sums.size(); i++) cout << sums[i] << " ";
//			cout << "\nrank\n";
//			for (int i = 0 ; i < sums.size(); i++) cout << rank[i] << " ";
//			cout << "\n";
		}
	}
	return (0);
}