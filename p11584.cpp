#include <iostream>
#include <vector>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	pair<double, double>					pr;
	vector<pair<double, double> >			v[11];

	v[0].push_back(make_pair(0, 1));
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < v[i].size(); j++) {
			v[i + 1].push_back(make_pair(v[i][j].first, v[i][j].first + (v[i][j].second - v[i][j].first) / 3));
			v[i + 1].push_back(make_pair(v[i][j].second - (v[i][j].second - v[i][j].first) / 3, v[i][j].second));
		}
	}
	/*
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j].first << " " << v[i][j].second << " | ";
		}
		cout << "\n";
	}
	*/
	int					t, a, b;
	double				val;
	bool				flag;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		val = (double)a / (double)b;
		for (int i = 0; i <= 10; i++) {
			flag = 0;
			for (int j = 0; j < v[i].size(); j++) {
				if (v[i][j].second < val) continue ;
				else if (v[i][j].first > val) break ;
				flag = 1;
				break ;
			}
			if (!flag) {
				cout << i;
				if (t) cout << "\n";
				break ;
			}
			if (i == 10) {
				cout << -1;
				if (t) cout << "\n";
			}
		}
	}
	return (0);
}