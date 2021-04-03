#include <iostream>
#include <vector>
#include <string>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			t, n;
	string		a, b;

	cin >> t;
	while (t--)
	{
		cin >> n >> a >> b;

		vector<int>		pair_vec;		// 0 is diff, 1 is equal
		int				flag = 0;
		int				a_zero_cnt = 0;
		int				a_one_cnt = 0;
		int				b_zero_cnt = 0;
		int				b_one_cnt = 0;
		int				can_convert[150002];

		for (int i = 0; i < n; i += 2)
		{
			if (i + 1 == n) break ;

			if ((a[i] == b[i] && a[i + 1] != b[i + 1]) ||
				(a[i] != b[i] && a[i + 1] == b[i + 1]))
			{
				flag = 1;
				break ;
			}

			//		can_convert check
			if (a[i] == '0')
				a_zero_cnt++;
			else
				a_one_cnt++;
			if (a[i + 1] == '0')
				a_zero_cnt++;
			else
				a_one_cnt++;
			if (a_zero_cnt == a_one_cnt)
				can_convert[i / 2] = 1;
			else
				can_convert[i / 2] = 0;
			//		b zero one cnt
			if (b[i] == '0')
				b_zero_cnt++;
			else
				b_one_cnt++;
			if (b[i + 1] == '0')
				b_zero_cnt++;
			else
				b_one_cnt++;
			//		pair_vec push			0 is diff, 1 is equal
			if (a[i] == b[i] && a[i + 1] == b[i + 1])
				pair_vec.push_back(1);
			else
				pair_vec.push_back(0);
		}
		if (n % 2)
		{
			if (a[n - 1] != b[n - 1]) flag = 1;
			if (a[n - 1] == '0')
				a_zero_cnt++;
			else
				a_one_cnt++;
			if (b[n - 1] == '0')
				b_zero_cnt++;
			else
				b_one_cnt++;
		}
		//			출력문
		if (flag || a_zero_cnt != b_zero_cnt)
		{
			cout << "NO";
		}
		else
		{
			int		conver_cnt = 0;
			int		flag = 0;

			for (int i = pair_vec.size() - 1; i >= 0; i--)
			{
				if ((pair_vec[i] + conver_cnt) % 2 == 0)
				{
					if (can_convert[i] == 1) conver_cnt++;
					else
					{
						flag = 1;
						break ;
					}
				}
			}
			if (flag)
				cout << "NO";
			else
				cout << "YES";
		}
		if (t)
			cout << endl;
	}

	return (0);
}
