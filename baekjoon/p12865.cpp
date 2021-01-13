#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int				n, k, w, v;

int		backpack(vector<pair<int, int> > wv, int can)
{
	pair<int, int>		pr;

	if (wv.empty()) return (0);
	pr = wv.back();
	wv.pop_back();
	if (pr.first > can)
		return (backpack(wv, can));
	else{
		return (max(backpack(wv, can), backpack(wv, can - pr.first) + pr.second));
	}
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<pair<int, int> >	wv;
	cin >> n >> k;
	for (int i = 0; i< n; i++){
		cin >> w >> v;
		wv.push_back(make_pair(w, v));
	}
	cout << backpack(wv, k);
	return (0);
}