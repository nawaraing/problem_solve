#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
#include <list>
//#include <algorithm>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int						n, m, a, idx, ans = 0;
	list<int>				l;
	list<int>::iterator		iter;

	cin >> n; cin >> m;

	for (int i = 0; i < n; i++) l.push_back(i + 1);
	for (int i = 0; i < m; i++) {
		cin >> a;
		idx = 0;
		for (iter = l.begin(); iter != l.end(); iter++) {
			if (*iter == a) break ;
			idx++;
		}
		// 길이가 짝수이면  l.size() / 2 가 정가운데, 홀수이면 l.size() / 2 부터 앞으로 가야함
		if (idx <= (int)l.size() / 2) {
			for (int j = 0; j < idx; j++) {
				l.push_back(l.front());
				l.pop_front();
				ans++;
			}
			if (l.front() == a) l.pop_front();
			else cout << "something wrong1\n";
		}
		else {
			for (int j = 0; j < (int)l.size() - idx; j++) {
				l.push_front(l.back());
				l.pop_back();
				ans++;
			}
			if (l.front() == a) l.pop_front();
			else cout << "something wrong2\n";
		}
	}
	cout << ans;
	return (0);
}
