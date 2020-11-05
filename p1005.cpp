#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int					t, n, k, a, b, maxi, order[1001], cost[1001];
	queue<int>			q, topo;
	vector<int>			reci[1001], send[1001];

	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> a;
			cost[i] = a;
			order[i] = 0;
			send[i].clear();
			reci[i].clear();
		}
		for (int i = 0; i < k; i++) {
			cin >> a >> b;
			send[a].push_back(b);
			reci[b].push_back(a);
			order[b]++;
		}
		cin >> b;
		while (topo.size())
			topo.pop();
		for (int i = 1; i <= n; i++) {
			if (!order[i]) q.push(i);
		}
		while (q.size()) {
			a = q.front();
			q.pop();
			topo.push(a);
			for (int i = 0; i < send[a].size(); i++)
				if (!(--order[send[a][i]])) q.push(send[a][i]);
		}
		//															after topolpgy
		while (topo.size()) {
			a = topo.front();
			topo.pop();
			maxi = 0;
			for (int i = 0; i < reci[a].size(); i++) {
				if (cost[reci[a][i]] > maxi) maxi = cost[reci[a][i]];
			}
			cost[a] += maxi;
			if (a == b) break ;
		}
		cout << cost[a];
		if (t) cout << "\n";
		/*
		while (topo.size()) {
			cout << topo.front() << " ";
			topo.pop();
		}
		*/
	}
	return (0);
}