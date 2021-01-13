#include <iostream>

using namespace std;

int			n, a, b, room[1001][1001], x, y;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> room[i][j];
		}
	}
	int		jin = room[a][b];
	bool	flag = false;
	for (int i =1 ; i <= n; i++)
	{
		if (i == a) continue ;
		if (room[i][b] > jin) {
			flag = true;
			break ;
		}
	}
	for (int i = 1; i <= n ; i++)
	{
		if (i == b) continue ;
		if (room[a][i] > jin) {
			flag = true ;
			break ;
		}
		if (flag) break ;
	}
	if (flag) cout << "ANGRY";
	else cout << "HAPPY";
	return (0);
}