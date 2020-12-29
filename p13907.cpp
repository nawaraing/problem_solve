#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int		n, m, k, s, d, a, b, w, p[30000];
int									graph[1001][1001];
priority_queue<pair<pair<int, int>, int> >		pq;
pair<pair<int, int>, int>				ppr;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k >> s >> d;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> w;
		graph[a][b] = graph[b][a] = w;
	}
	for (int i = 0; i < k; i++)
		cin >> p[i];
	pq.push(make_pair(make_pair(0, 0), s));
	while (pq.size())
	{
		ppr = pq.top();
		pq.pop();
		if ()
	}
	return (0);
}