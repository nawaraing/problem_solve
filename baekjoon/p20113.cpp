#include <iostream>

using namespace std;

int	n, vote[101];
int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int		a;
		cin >> a;
		vote[a]++;
	}
	int		one = 0;
	int		two = 0;
	int		who = 0;
	for (int i = 1; i <= n; i++) {
		// cout << vote[i] << " ";
		if (one < vote[i])
		{
			who = i;
			two = one;
			one = vote[i];
		}
		else if (two < vote[i])
			two = vote[i];
	}
	if (who == 0 || one == two)
		cout << "skipped";
	else
	{
		cout << who;
	}
	
	return (0);
}