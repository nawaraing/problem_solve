#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int			len;
string		cake;
pair<int, int>		cnt[200001];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> len;
	cin >> cake;
	for (int i =0; i < len; i++)
	{
		cnt[i + 1].first = cnt[i].first;
		cnt[i + 1].second = cnt[i].second;
		if (cake[i] == 's') cnt[i + 1].first++;
		else cnt[i + 1].second++;
	}
	int		idx1 = 0;
	int		idx2 = len / 2;
	for (int i = 0; i < len / 2; i++)
	{
		if (cnt[idx2].first - cnt[idx1].first == len / 4 &&\
			cnt[idx2].second - cnt[idx1].second == len / 4)
			break ;
		idx1++; idx2++;
	}
	if (idx1 == 0)
	{
		cout << "1\n" << idx2;
	}
	else {
		cout << "2\n" << idx1 << " " << idx2;
	}
	return (0);
}