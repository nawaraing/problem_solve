#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		t, n, a;

	cin >> t;
	while (t--)
	{
		vector<int>		v;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		int		start = 0;
		int		most = -1;
		for (int i = 0; i < n - 1; i++)
		{
			if (v[i] != v[i + 1])
			{
				if (most < i + 1 - start)
					most = i + 1 - start;
				start = i + 1;
			}
		}
		if (most < n - start)
			most = n - start;
		// if (most == -1)
			// most = n;
		// cout << "most: " << most << endl;
		// cout << "ans   : ";
		if (most <= n / 2)
		{
			if (n % 2)
				cout << 1;
			else
				cout << 0;
		}
		else
			cout << most - (n - most);
		if (t) cout << endl;
	}


	return (0);
}
