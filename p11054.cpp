#include <iostream>

using namespace std;

int			increase[1000], decrease[1000], arr[1000];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		increase[i] = 1;
		decrease[i] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		int		tmp = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && tmp < increase[j]) tmp = increase[j];
		}
		increase[i] = tmp + 1;
	}
	for (int i = n - 1; i > 0; i--)
	{
		int		tmp = 0;
		for (int j = n - 1; j > i; j--)
		{
			if (arr[i] > arr[j] && tmp < decrease[j]) tmp = decrease[j];
		}
		decrease[i] = tmp + 1;
	}
	int		maxi = 0;
/* 	for (int i = 0; i < n; i++)
		cout << increase[i] << " ";
	cout << "\n";
	for (int i = 0; i < n; i++)
		cout << decrease[i] << " ";
	cout << "\n";
 */	for (int i = 0; i < n; i++)
	{
		int		cur = increase[i] + decrease[i] - 1;
		if (maxi < cur) maxi = cur;
	}
	cout << maxi;
	return (0);
}