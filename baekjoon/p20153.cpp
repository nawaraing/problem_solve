#include <iostream>
#include <vector>

using namespace std;

int			n, a;
vector<int>		v;
int			sum, ret;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	while (n--)
	{
		cin >> a;
		v.push_back(a);
		sum ^= a;
	}
	ret = sum;
	for (int i = 0; i < v.size(); i++)
	{
		if (ret < (sum ^ v[i]))
			ret = (sum ^ v[i]);
	}
	cout << ret << ret;
	return (0);
}