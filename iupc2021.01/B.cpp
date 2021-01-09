#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int		n, m;
vector<int>		v;

long long		ft_find(long long start, long long end, long long element)
{
	long long		mid = (start + end) / 2;

	if (start == end)
	{
		if (v[start] == element) return (start);
		else return (-1);
	}
	long long		tmp = ft_find(start, mid, element);
	if (tmp != -1) return (tmp);
	tmp = ft_find(mid + 1, end, element);
	if (tmp != -1) return (tmp);
	return (-1);
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	while (n--)
	{
		long long		a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	while (m--)
	{
		long long		a;
		cin >> a;
		cout << ft_find(0, v.size() - 1, a) << "\n";
	}
	return (0);
}