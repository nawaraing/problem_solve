#include <iostream>
#include <list>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	bool			bulb[100000];
	int				cnt = 0, ans = 0;
	int				n, k;
	list<int>		lst;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> bulb[i];
		if (bulb[i]) cnt++;
	}
	if (cnt % k) {
		cout << "Insomnia";
		return (0);
	}
	for (int i = 0; i < n; i++) {
		if (lst.size() && lst.front() == i) lst.pop_front();
		if (((int)bulb[i] + (int)lst.size()) % 2) {
			ans++;
			lst.push_back(i + k);
		}
	}
	cout << ans++;
	return (0);
}