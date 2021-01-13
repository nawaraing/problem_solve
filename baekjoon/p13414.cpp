#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stack>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string		s1;
	int			k , l;
	vector<string>		v;
	int					cnt = 0;
	set<string>			s;
	stack<int>			st;

	cin >> k >> l;
	while (l--)
	{
		cin >> s1;
		v.push_back(s1);
	}
	for (int i = k - 1; i <= 0; i--)
	{
		if (s.find(v[i]) == s.end())
			s.insert(v[i]);
	}
	return (0);
}