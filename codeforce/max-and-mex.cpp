#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>		v;
int				t, n, k, a;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--)
	{
		v.clear();
		int		maxi = -1;
		int		cnt = 0;
		cin >> n >> k;
		for (int i =0; i < n; i++)
		{
			cin >> a;
			v.push_back(a);
			if (maxi < a)
				maxi = a;
		}
		cnt = n;
		sort(v.begin(), v.end());
		int		mexi;
		if (v[0] != 0) mexi = 0;
		else {
			for (int i =0; i < n - 1; i++)
			{
				mexi = v[i] + 1;
				if (v[i] + 1 != v[i + 1])
					break ;
			}
			if (mexi == v.back()) mexi = maxi + 1;
		}
		if (k == 0)
		{
			cout << cnt;
			if (t) cout << "\n";
			continue ;
		}
		if (mexi < maxi)
		{
			long long sum = (long long)mexi + (long long)maxi;
			if (sum % 2) sum++;
			sum /= 2;
			cnt++;
			for (int i = 0 ; i < n; i++)
			{
				if (v[i] > sum)
					break ;
				if (v[i] == sum)
				{
					cnt--;
					break ;
				}
			}
		}
		else {
			cnt += k;
		}
		cout << cnt;
		if (t) cout << "\n";
	}
	return (0);
}
