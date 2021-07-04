#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int>		v;
	int		n, a;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	cout << v[0] << " " << v.back();
	return (0);
}
