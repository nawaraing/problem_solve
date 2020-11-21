#include <iostream>
#include <vector>

using namespace std;

int			n, q, dot[200001], b, c, d, tmp;			//		dot[i]에는 i 정점의 부모 번호가 저장되어 있다.
vector<int>	v;
bool		flag;


int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> q;
	for (int i = 2; i < n + 1; i++) {
		cin >> dot[i];
	}
	while (q--) {
		cin >> b >> c >> d;
		tmp = b;
		v.clear();
		while (tmp) {
			v.push_back(tmp);
			tmp = dot[tmp];
		}
		tmp = c;
		flag = 0;
		while (tmp) {
			for (int i = 0; i < v.size(); i++) {
				if (tmp == v[i]) {
					flag = 1;
					break ;
				}
			}
			if (flag) break ;
			tmp = dot[tmp];
		}
		if (flag) {
			cout << "YES";
			if (q) cout << "\n";
			if (d) dot[b] = 0;
		}
		else {
			cout << "NO";
			if (q) cout << "\n";
			if (d) dot[c] = 0;
		}
	}
	return (0);
}