#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			n;
	int			num, cnt = 0;
	vector<int>	v;
	v.clear();
	v.push_back(0);
	cin >> n;
	while (n--)
	{
		cin >> num;
		if (v.back() < num)
		{
			v.push_back(num);
			cnt++;
		}
		else
			*lower_bound(v.begin(), v.end(), num) = num;			
	}
	cout << cnt;
	return (0);
}