#include <iostream>
#include <vector>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int>		bulb;
	int				n, k, pre = -1, a, ans = 0;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (pre == a) continue ;
		bulb.push_back(a);
		pre = a;
	}
	cout << "start\n";
	for (int i = 0; i < bulb.size(); i++) cout << bulb[i] << " ";
	cout << "\n\n";
	for (int dist = 2; dist < bulb.size(); dist++) {
		for (int i = 0; i + dist < bulb.size(); i++) {
			if (bulb[i] != bulb[i + dist]) continue ;
			ans += dist - 1;
			bulb.erase(bulb.begin() + i, bulb.begin() + i + dist);
			i = -1;
			dist = 2;
			cout << "in\n";
			for (int i = 0; i < bulb.size(); i++) cout << bulb[i] << " ";
			cout << "\n\n";
		}
	}
	ans += bulb.size() - 1;
	cout << ans;
	return (0);
}