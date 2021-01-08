#include <iostream>

using namespace std;

int			n, m;
int			mem[31][31];


int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j =0; j < m; j++)
		{
			cin >> mem[i][j];
		}
	}
	int			ans = 0;
	for (int ch1 = 0; ch1 < m; ch1++)
	{
		for (int ch2 = ch1 + 1; ch2 < m; ch2++)
		{
			for (int ch3 = ch2 + 1; ch3 < m; ch3++)
			{
				int		total = 0;
				for (int member = 0; member < n; member++)
				{
					int		maxi = mem[member][ch1];
					if (maxi < mem[member][ch2]) maxi = mem[member][ch2];
					if (maxi < mem[member][ch3]) maxi = mem[member][ch3];
					total += maxi;
				}
				if (ans < total) {
					ans = total;
					// cout << ch1 << " " << ch2 << " " << ch3 << "\n";
				}
			}
		}
	}
	cout << ans;
	return (0);
}