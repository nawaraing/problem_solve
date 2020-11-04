#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int				dp[10001], c;
vector<int>		coin;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		n, k;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> c;
		if (coin.end() != find(coin.begin(), coin.end(), c))
			coin.push_back(c);
	}
	sort(coin.begin(), coin.end());
	for (int i = 0; i < (int)coin.size(); i++) {
		if (!dp[coin[i]]) dp[coin[i]] = 
	}
	return (0);
}