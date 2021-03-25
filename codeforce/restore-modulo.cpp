#include <iostream>
#include <vector>

using namespace std;

int		t, n;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--)
	{
		cin >> n;
		vector<long long>		v;
		long long				a;
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			v.push_back(a);
		}
		if (n == 1 || n == 2)
		{
			cout << 0;
			if (t) cout << "\n";
			continue ;
		}
		const long long	sub = v[1] - v[0];
		long long		maxi = v[0];
		long long		mod = -1;
		for (int i = 1; i < n - 1; i++)
		{
			//			sub > 0
			if (sub > 0)
			{
				if (maxi < v[i])
					maxi = v[i];
				if (maxi < v[i + 1])
					maxi = v[i + 1];
				if (v[i + 1] - v[i] != sub)
				{
					if (v[i + 1] - v[i] >= 0)
					{
						cout << -1;
						if (t) cout << "\n";
						break ;
					}
					if (mod == -1)
					{
						mod = sub - (v[i + 1] - v[i]);
						// if (v[i + 1] != (v[i] + sub) % mod)
						// {
						// 	cout << -1;
						// 	if (t) cout << "\n";
						// 	break ;
						// }
					}
					else if (mod != sub - (v[i + 1] - v[i]))
					{
						cout << -1;
						if (t) cout << "\n";
						break ;
					}
				}
				if (i == n - 2)		// sub > 0 		print
				{
					if (mod == -1)
					{
						cout << 0;
						if (t) cout << "\n";
						break ;
					}
					if (maxi >= mod)
					{
						cout << -1;
						if (t) cout << "\n";
						break ;
					}
					else
					{
						cout << mod << " " << sub;
						if (t) cout << "\n";
						break ;
					}
				}
			}
			else if (sub < 0)		//		sub < 0
			{
				if (maxi < v[i])
					maxi = v[i];
				if (maxi < v[i + 1])
					maxi = v[i + 1];
				if (v[i + 1] - v[i] != sub)		// sub만큼씩 줄다가  불규칙하네!
				{
					if (v[i] + sub >= 0)		//	v[i] 에서 sub 만큼 더 줄어들 수 있는데? 에러네
					{
						cout << -1;
						if (t) cout << "\n";
						break ;
					}
					else if (v[i + 1] - v[i] <= 0)		// sub이 또 줄긴했는데 불규칙하네? 에러지
					{
						cout << -1;
						if (t) cout << "\n";
						break ;
					}
					else if (mod == -1)
					{
						mod = v[i + 1] - v[i] - sub;
						// if (mod + sub != v[i + 1])
						// {
						// 	cout << -1;
						// 	if (t) cout << "\n";
						// 	break ;
						// }
					}
					else if (mod != v[i + 1] - v[i] - sub)
					{
						cout << -1;
						if (t) cout << "\n";
						break ;
					}
				}
				if (i == n - 2)				// sub < 0		print
				{
					if (mod == -1)
					{
						cout << 0;
						if (t) cout << "\n";
						break ;
					}
					if (maxi >= mod)
					{
						cout << -1;
						if (t) cout << "\n";
						break ;
					}
					else
					{
						cout << mod << " " << sub + mod;
						if (t) cout << "\n";
						break ;
					}
				}
			}
			else				// sub == 0
			{
				if (v[i + 1] - v[i] != 0)
				{
					cout << -1;
					if (t) cout << "\n";
					break ;
				}
				if (i == n - 2)
				{
					cout << 0;
					if (t) cout << "\n";
					break ;
				}
			}
		}
	}
	return (0);
}
