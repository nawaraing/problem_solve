#include <iostream>

using namespace std;

char		field[20][20];
int			col[20];
int			n;
int			minn = 2147483647;

void	backtracking(int idx)
{
	if (idx == n)
	{
		// cout << "col : ";
		// for (int i = 0; i < n; i ++) cout << col[i] << " ";
		// cout << "\n";
		int		cnt = 0;
		for (int j = 0; j < n; j++)
		{
			int t = 0;
			for (int i = 0; i < n; i++)
			{
				if (col[i] == 0 && field[i][j] == 'T') t++;
				else if (col[i] == 1 && field[i][j] == 'H') t++;
			}
			// cout << "t : " << t << "\n";
			if (t < n - t)
				cnt += t;
			else cnt += n - t;
		}
		if (cnt < minn) minn = cnt;
		return ;
	}
	backtracking(idx + 1);
	col[idx] = 1;
	backtracking(idx + 1);
	col[idx] = 0;
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	char		c;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> c;
			field[i][j] = c;
		}
	}
	backtracking(0);
	cout << minn;
	return (0);
}