#include <iostream>

using namespace std;

long long		n, block[500][500], sum = 0;
pair<long long, long long>	zero;
long long		ans;

bool	ft_horizon(void)
{
	long long		tmp = 0;
	for (int i = 0; i < n; i++)
	{
		if (zero.first == i) continue ;
		tmp = 0;
		for (int j = 0; j < n; j++)
		{
			tmp += block[i][j];
		}
		if (sum == 0) sum = tmp;
		else if (sum != tmp)
			return (false);
	}
	ans = sum;
	for (int i = 0; i < n;i++)
	{
		ans -= block[zero.first][i];
	}
	block[zero.first][zero.second] = ans;
	return (true);
}

bool	ft_vertical(void)
{
	long long tmp = 0;;
	for (int j = 0; j < n; j++)
	{
		tmp = 0;
		for (int i = 0; i < n; i++)
		{
			tmp += block[i][j];
		}
		if (tmp != sum)	return (false);
	}
	return (true);
}

bool	ft_diagonal(void)
{
	long long tmp1 = 0, tmp2 = 0;
	for (int i = 0; i< n; i++)
	{
		tmp1 += block[i][i];
		tmp2 += block[i][n - i - 1];
	}
	if (sum != tmp1 || sum != tmp2) return (false);
	return (true);
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i =0 ; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> block[i][j];
			if (block[i][j] == 0)
				zero = make_pair(i, j);
		}
	}
	if (ft_horizon() == false)
		cout << -1;
	else if (ft_vertical() == false)
		cout << -1;
	else if (ft_diagonal() == false)
		cout << -1;
	else cout << ans;
	// cout << "\nsum : " << sum;
	return (0);
}