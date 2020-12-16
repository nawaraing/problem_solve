#include <iostream>
#include <cmath>

using namespace std;

int			t, n, a, sequ[100001];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			sequ[i] = a;
		}
		sequ[n] = 0;
		int		two_cnt = 0;
		bool	is_minus = 0;
		int		front = 0;
		for (int back = 0; back < n; back++)
		{
			if (sequ[back] == 2 || sequ[back] == -2)
				two_cnt++;
			if (sequ[back] < 0) is_minus = !is_minus;
			if (sequ[back] == 0) {
				if (front == back) {
					front++;
					continue ;
				}
				else if (back - front == 1) {
					front = back + 1;
				}
			}
		}
	}
	return (0);
}