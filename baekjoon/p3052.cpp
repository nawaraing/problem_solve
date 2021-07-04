#include <iostream>
#include <set>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	set<int>		s;
	int				a;

	for (int i = 0; i < 10; i++)
	{
		cin >> a;
		a %= 42;
		s.insert(a);
	}
	cout << s.size();
	return (0);
}
