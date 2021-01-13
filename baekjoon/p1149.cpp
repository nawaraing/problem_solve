#include <iostream>
#include <algorithm>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int				r, g, b, n, pre[3];

	cin >> n;
	cin >> pre[0] >> pre[1] >> pre[2];
	for (int i = 0; i < n - 1; i++) {
		cin >> r >> g >> b;
		r += min(pre[1], pre[2]);
		g += min(pre[0], pre[2]);
		b += min(pre[1], pre[0]);
		pre[0] = r; pre[1] = g; pre[2] = b;
	}
	cout << min(pre[1], min(pre[0], pre[2]));
	return (0);
}