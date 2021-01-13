#include <iostream>
#include <vector>

using namespace std;

int			n;
vector<char>	team[8];

void	ft_half(int start, int end, int day)
{
	int		mid = (start + end) / 2;

	for (int i = start; i <= mid; i++)
		team[day].push_back('A');
	for (int i = mid + 1; i <= end; i++)
		team[day].push_back('B');
	if (day == 7) return ;
	ft_half(start, mid, day + 1);
	ft_half(mid + 1, end, day + 1);
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	ft_half(1, n, 1);
	for (int i = 1; i <= 7; i++)
	{
		int		flag = 0;
		char	c = team[i][0];
		for (int j = 0; j < n; j++)
		{
			if (c != team[i][j]) flag = 1;
			if (j == n - 1 && flag == 0)
			{
				if (c == 'A') cout << 'B';
				else cout << 'A';
			}
			else cout << team[i][j];
		}
		cout << "\n";
	}
	return (0);
}