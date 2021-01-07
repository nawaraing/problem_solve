#include <iostream>

using namespace std;

int		n, cards[100001];
int		me, you, aset, bset, ret;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int			a;
		cin >> a;
		cards[i] = a;
		if (i % 2) aset += a;
		else bset += a;
	}
	int		last = cards[n];
	ret = aset;
	for (int i = 1; i <= n ; i++)
	{
		if (i % 2)
		{
			if (ret < me + bset) ret = me + bset;
			me += cards[i];
			aset -= cards[i];
		}
		else
		{
			if (ret < me + bset - last) ret = me + bset - last;
			you += cards[i];
			bset -= cards[i];
		}
	}
	cout << ret;
	return (0);
}