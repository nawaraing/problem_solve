#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<pair<int, int> >			dots;
int								n, x, y, start_point = -1, end_point;

bool	ft_y_sort(pair<int, int> a, pair<int, int> b) {return (a.second < b.second);}

int		ft_get_dist(pair<int, int> a, pair<int, int> b) {
	pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}

int		ft_dfs(int start, int len) {
	int				tmp = len;
	if (len % 2) tmp++;
	int				minn = min(ft_dfs(start, tmp / 2), ft_dfs(start + tmp / 2, tmp / 2));
	int				mid_x = dots[start + tmp / 2].first;
	for (int i = start; i < start + len; i++) {
		if (pow(dots[i].first - mid_x, 2) > minn)
			continue ;
		if (start_point == -1) start_point = i;
		else end_point = i;
	}
	sort(dots.begin() + start_point, dots.begin() + end_point + 1, ft_y_sort);
	int tmp_start = start_point;
	for (int i = start_point; i <= end_point; i++) {
		for (int j = tmp_start; j <= end_point; j++) {
			if (pow(dots[j].second - dots[i].second, 2) > minn) {
				if (j < i) tmp_start = j + 1;
				continue ;
			}
			int		dist;
			if ((dist = ft_get_dist(dots[i], dots[j])) < minn) minn = dist;
		}
	}
	sort(dots.begin() + start_point, dots.begin() + end_point + 1);
	return (minn);
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		dots.push_back(make_pair(x, y));
	}
	sort(dots.begin(), dots.end());
	cout << ft_dfs(0, dots.size());
	return (0);
}