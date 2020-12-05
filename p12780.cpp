#include <iostream>
#include <cstring>
using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string					h, n;
	int						res = 0;

	cin >> h >> n;
	for (int i = 0; i < h.size(); i++) {
		bool	flag = 0;
		for (int j = 0; j < n.size(); j++) {
			if (i + j >= h.size()) break ;
			if (h[i + j] != n[j]) {
				flag = 1;
				break ;
			}
		}
		if (!flag) res++;
	}
	cout << res;
	return (0);
}