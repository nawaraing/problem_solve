#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>


using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int						n, l, a, pcnt = 0, ncnt = 0, time = 0;
	pair<int, int>			p;		//	개미의 초기 위치/방향, 추락 시간
	vector<pair<int, int> >	v;

	cin >> n >> l;
	p = make_pair(0, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (a > 0)
		{
			pcnt++;
			v.push_back(make_pair(a, i));
			time = l - a;
		}
		else
		{
			ncnt++;
			v.push_back(make_pair(-a, i));
			time = -a;
		}
		if (p.second < time){
			p = make_pair(a, time);
		}
	}
	sort(v.begin(), v.end());
	if (p.first > 0)
		pcnt--;
	else
		ncnt--;
	while (pcnt--) v.pop_back();
	cout << v.back().second << " " << p.second;
	return (0);
}