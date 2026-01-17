#include <iostream>
#include <queue>

using namespace std;

queue<int> qu;
int k, n, tmp;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		qu.push(i);
	}

	cout << "<";
	while (!qu.empty()) {
		for (int i = 0; i < k; i++) {
			tmp = qu.front();
			qu.pop();
			if (i == k - 1) {
				// cout << "tmp: " << tmp << "\n";
				cout <<  tmp;
				if (qu.empty()) {
					cout << ">";
				} else {
					cout << ", ";
				}
			} else {
				qu.push(tmp);
			}
		}
	}
}
