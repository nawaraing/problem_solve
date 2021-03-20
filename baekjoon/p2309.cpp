#include <iostream>
#include <algorithm>

using namespace std;

int			key[10];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		sum = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> key[i];
		sum += key[i];
	}
	sum -= 100;
	int		flag =0;
	for (int i = 0 ; i< 9; i++)
	{
		for (int j = i + 1; j < 9 ;j++)
		{
			if (key[i] + key[j] == sum)
			{
				// cout << key[i] << " " << key[j] << "  !!\n";
				key[i] = 0;
				key[j] = 0;
				flag = 1;
				break ;
			}
		}
		if (flag) break;
	}
	sort(key, key + 9);
	for (int i  = 2; i < 9; i++)
	{
		cout << key[i] << "\n";
	}
	return (0);
}