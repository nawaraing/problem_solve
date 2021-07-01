#include <iostream>
#include <queue>

using namespace std;

int		mp[101][101];
int		n;


int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mp[i][j];
		}
	}
	
	return (0);
}