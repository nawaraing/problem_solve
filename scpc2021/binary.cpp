#include <iostream>
#include <string>

using namespace std;

int		n, t;
string	b;

int		is_right_valid(int idx)
{
	if (idx + t >= n)
		return 0;
	if (idx + 2 * t >= n)
		return 1;
	if (b[idx + 2 * t] == '0')
		return 0;
	else
		return 1;
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> n >> t >> b;
		string a((size_t)n, (char)'0');
		for (size_t i = 0; i < n; i++)
		{
			if (b[i] == '0')
				continue ;
			if (i - t > 0 && a[i - t] == '1')
				continue ;
			if (is_right_valid(i))
				a[i + t] = '1';
			else
				a[i - t] = '1';
		}
		cout << "Case #" << test_case + 1 << "\n" << a << "\n";
	}
	return (0);
}
