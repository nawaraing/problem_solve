#include <iostream>

using namespace std;

int			t;
int			n;
pair<long long, long long>		table[1000001];
long long			tm[1000001];


int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--)
	{
		cin >> n;
		long long		a, b;
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			table[i] = make_pair(a, b);
		}
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			tm[i] = a;
		}
		long long	cur = table[0].first + tm[0];
		for (int i = 0; i < n - 1; i++)
		{
			long long 		wait = table[i].second - table[i].first;
			if (wait % 2) wait++;
			wait /= 2;
			cur += wait;
			if (cur < table[i].second)
				cur = table[i].second;
			cur += table[i + 1].first - table[i].second + tm[i + 1];
			// cout << "cur: " << cur << "\n";
		}
		cout << cur;
		if (t) cout << "\n";
	}
	return (0);
}
