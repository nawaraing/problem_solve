#include <iostream>
#include <queue>

using namespace std;

int		n, m;
int		maps[101], visit[101];
priority_queue<pair<int, int> > pq; //< -cnt, cur >

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	int		a, b;
	for (int i = 0; i < m + n; i++)
	{
		cin >> a >> b;
		maps[a] = b;
	}
	visit[1] = 1;
	pq.push(make_pair(0, 1));
	while (!pq.empty())
	{
		pair<int, int>	cur = pq.top();
		pq.pop();
		for (int dice = 1; dice <= 6; dice++)
		{
			int		next = cur.second + dice;
			if (maps[next] != 0)
				next = maps[next];
			if (next == 100) {
				cout << -cur.first + 1;
				return (0);
			}
			else if (next < 100 && visit[next] == 0)
			{
				visit[next] = 1;
				pq.push(make_pair(cur.first - 1, next));
			}
		}
	}
	return (0);
}