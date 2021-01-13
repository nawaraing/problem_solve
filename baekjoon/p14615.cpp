#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int				n, m, a, b;
vector<int>		righ[100001], rev[100001];
bool			f[100001], ba[100001];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		righ[a].push_back(b);
		rev[b].push_back(a);
	}
	queue<int>		q;
	int				node, tmp;

	q.push(1);
	f[1] = true;
	while (!q.empty())
	{
		node = q.front();
		q.pop();
		for (int i = 0; i < righ[node].size(); i++)
		{
			tmp = righ[node][i];
			if (!(f[tmp]))
			{
				q.push(tmp);
				f[tmp] = true;
			}
		}
	}
	while (!q.empty())
		q.pop();
	q.push(n);
	ba[n] = true;
	while (!q.empty())
	{
		node = q.front();
		q.pop();
		for (int i = 0; i < rev[node].size(); i++)
		{
			tmp = rev[node][i];
			if (!(ba[tmp]))
			{
				q.push(tmp);
				ba[tmp] = true;
			}
		}
	}
	int		t;
	cin >> t;
	while (t--)
	{
		cin >> a;
		if (f[a] && ba[a])
			cout << "Defend the CTP";
		else
			cout << "Destroyed the CTP";
		if (t) cout << "\n";
	}
	return (0);
}