#include <iostream>
#include <vector>

using namespace std;

int		n, m, k, a, infect[100001];
vector<int>		meet[100001];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> k;
		while (k--)
		{
			cin >> a;
			meet[i].push_back(a);
		}
	}
	for (int i = 1; i <= n; i++)
		cin >> infect[i];
	for (int i = m - 1; i >= 0; i--)
	{

	}
	return (0);
}