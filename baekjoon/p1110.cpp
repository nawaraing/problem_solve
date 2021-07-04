#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			n, ret = 0;
	cin >> n;
	int		calcul = n;
	while (1)
	{
		ret++;
		int		div = calcul / 10;
		int		mod = calcul % 10;
		calcul = mod * 10 + ((mod + div) % 10);
		if (n == calcul)
		{
			cout << ret;
			return 0;
		}
	}

	return (0);
}
