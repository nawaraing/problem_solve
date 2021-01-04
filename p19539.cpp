#include <iostream>
#include <vector>

using namespace std;

int			tree[100000];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		n, h, sum = 0, odd = 0, two = 0;
	cin >> n;
	for(int i = 0; i < n ; i++)
	{
		cin >> h;
		sum += h;
		tree[i] = h;
		if (h % 2) odd++;
	}
	if (sum % 3) cout << "NO";
	else
	{
		sum /= 3;
		if (odd > sum) cout << "NO";
		else cout << "YES";
	}
	return (0);
}