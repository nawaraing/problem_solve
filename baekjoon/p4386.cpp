#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>

using namespace std;

int			n, visit[101];
double		x, y, dist[101][101];
pair<double, double>		stars[101];
vector<int>				v;

double	ft_dist_sqr(pair<double, double> a, pair<double, double> b)
{
	return ((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	double	ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		stars[i] = make_pair(x, y);
	}
	if (n == 1) {
		cout << 0; return 0;
	}
	v.push_back(0);
	visit[0] = 1;
	for (int cnt = 0; cnt < n - 1; cnt++)
	{
		double	minn = 2000;
		int		idx = -1;
		for (int i = 0; i < v.size(); i++)
		{
			pair<double, double>	conn = stars[v[i]];
			for (int j = 0; j < n; j++)
			{
				if (visit[j]) continue ;
				if (v[i] == j) continue ;
				if (minn > ft_dist_sqr(conn, stars[j]))
				{
					minn = ft_dist_sqr(conn, stars[j]);
					// cout << v[i] << " " << j << " " << minn << "\n";
					idx = j;
				}
			}
		}
		visit[idx] = 1;
		v.push_back(idx);
		// cout << minn << "\n";
		ans += sqrt(minn);
	}
	printf("%.2lf", ans);
	return (0);
}