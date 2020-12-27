#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

string	a, b;
pair<int, int>			dp[1001][1001];		// < len, vv idx >
vector<vector<char> >	vv;
vector<char>			v;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> a >> b;
	vv.push_back(v);
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <=b.size(); j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j].first = dp[i - 1][j - 1].first + 1;
				v = vv[dp[i - 1][j - 1].second];
				v.push_back(a[i - 1]);
				vv.push_back(v);
				dp[i][j].second = vv.size() - 1;
			}
			else
			{
				if (dp[i - 1][j].first > dp[i][j - 1].first) {
					dp[i][j].first = dp[i - 1][j].first;
					dp[i][j].second = dp[i - 1][j].second;
				}
				else
				{
					dp[i][j].first = dp[i][j - 1].first;
					dp[i][j].second = dp[i][j - 1].second;
				}
			}
		}
	}
	cout << dp[a.size()][b.size()].first;
	if (dp[a.size()][b.size()].first) {
		cout << "\n";
		int		idx = dp[a.size()][b.size()].second;
		for (int i = 0; i < vv[idx].size(); i++)
		{
			cout << vv[idx][i];
		}
	}
	return (0);
}