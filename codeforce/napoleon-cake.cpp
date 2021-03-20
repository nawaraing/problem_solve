#include <iostream>

using namespace std;

int		t, n;
int		cake[200001];
int		input[200001];

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
			cin >> input[i];
			cake[i] = 0;
		}
		int		extra = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (extra < input[i])
				extra = input[i];
			if (extra > 0)
			{
				extra--;
				cake[i] = 1;
			}
		}
		for (int i = 0; i < n; i++)
		{
			cout << cake[i];
			if (i != n - 1) cout << " ";
		}
		if (t) cout << "\n";
	}

	return (0);
}
