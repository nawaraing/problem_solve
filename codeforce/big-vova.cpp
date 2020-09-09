#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>

using namespace std;

int gcd(int x,int y)
{
 int z=x%y;
 if(z==0)
 return(y);
 else
 return(gcd(y,z));
}


int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			t, n, a, g, gd;
	list<int>		l, ans;
	list<int>::iterator	iter, keep;

	cin >> t;
	while (t--) {
		cin >> n;
		while (n--) {
			cin >> a;
			l.push_back(a);
		}
		iter = l.begin();
		keep = iter;
		iter++;
		while (iter != l.end()) {
			if (*keep < *iter) keep = iter;
			iter++;
		}
		ans.push_back(*keep);
		gd = *keep;
		l.erase(keep);
		while (l.size()) {
			iter = l.begin();
			keep = iter;
			g = 0;
			while (iter != l.end()) {
				if (g < gcd(gd, *iter)) {
					keep = iter;
					g = gcd(gd, *iter);
				}
				iter++;
			}
			ans.push_back(*keep);
			gd = g;
			l.erase(keep);
		}
		cout << ans.front();
		ans.pop_front();
		while (ans.size()) {
			cout << " " << ans.front();
			ans.pop_front();
		}
		if ( t != 0 ) cout << "\n";
	}
	return (0);
}
