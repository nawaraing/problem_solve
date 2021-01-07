#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int>			recipe[200000];
int					need[200001], have[200001], ret[200001];
bool				visit[200001];
queue<int>			q;
int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int				n, m;
	cin >> n >> m;
	for (int i =0 ; i < m; i++)
	{
		cin >> need[i];
		for (int j =0; j < need[i]; j++)
		{
			int		a;
			cin >> a;
			recipe[a].push_back(i);
		}
		cin >> ret[i];
	}
	int		l;
	cin >> l;
	int			cnt = 0;
	while (l--) {
		int		a;
		cin >> a;
		q.push(a);
		visit[a] = true;
		cnt++;
	}
	while (q.size())
	{
		int		a = q.front();
		q.pop();
		for (int i = 0; i < recipe[a].size(); i++)
		{
			have[recipe[a][i]]++;
			if (have[recipe[a][i]] == need[recipe[a][i]] && visit[ret[recipe[a][i]]] == 0)
			{
				visit[ret[recipe[a][i]]] = true;
				cnt++;
				q.push(ret[recipe[a][i]]);
			}
		}
	}
	cout << cnt << "\n";
	for (int i = 1; i <= n; i++)
	{
		cnt--;
		if (visit[i]) {
			cout << i << " ";
			// if (cnt) cout << " ";
		}
	}
	return (0);
}