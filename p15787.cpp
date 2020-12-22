#include <iostream>
#include <set>

using namespace std;

#define MAXI ((1<<20) - 1)

int		n, m, train[100001];
int		a, b, c;

class cmd
{
	public:
	int		seat(int num)
	{
		return (1 << (num - 1));
	}

	int		addiction(int train, int num)
	{
		return (train | seat(num));
	}

	int		minus(int train, int num)
	{
		return (train & (MAXI - seat(num)));
	}

	int		front(int train)
	{
		return (MAXI & (train << 1));
	}

	int		back(int train)
	{
		return (train >> 1);
	}
};

int		main(void)
{
	class cmd		tmp;

	cin >> n >> m;
	while (m--)
	{
		for (int i = 1; i <= n; i++)
		 	cout << train[i] << " ";
		cout << "\n";
		cin >> a;
		if (a == 1 || a == 2)
		{
			cin >> b >> c;
			if (a == 1)
				train[b] = tmp.addiction(train[b], c);
			else train[b] = tmp.minus(train[b], c);
		}
		else
		{
			cin >> b;
			if (a == 4)
				train[b] = tmp.back(train[b]);
			else train[b] = tmp.front(train[b]);
		}
	}
/* 	set<int>		s;
	for (int i =0; i < n;i++)
	{
		s.insert(train[i]);
	}
	cout << s.size();
*/
	int		ans = 0;
	bool	flag = 0;
	for (int i =1; i <= n;i++)
	{
		flag = 0;
		for (int j = 1; j < i; j++)
		{
			if (train[i] == train[j])
				flag = 1;
			if (flag)
				break;
		}
		if (!flag)
			ans++;
	}
	cout << ans;
}