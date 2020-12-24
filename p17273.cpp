#include <iostream>

using namespace std;

int			n, m, cmd;
int			card[1][2];
int			sett[1];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i =0; i < n; i++)
	{
		cin >> card[i][0] >> card[i][1];
	}
	for (int i = 0; i < m; i++) {
		cin >> cmd;
		if (cmd >= card[0][sett[0]])
			sett[0] = (sett[0] + 1) % 2;
	}
	if (sett[0] % 2) cout << card[0][1];
	else cout << card[0][0];
	return (0);
}