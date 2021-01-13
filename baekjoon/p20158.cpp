#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<vector<int> >		pq; // [-time, c, r, 방향, 가속도]
vector<int>							cur, nextv;
int									maps[100][100];
int									visit[100][100][4][100]; // [북동남서]
int									dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int									n;
int									a;
int									done;

int		is_valid(int x, int y)
{
	if (x < 0 || x >= n) return (0);
	if (y < 0 || y >= n) return (0);
	return (1);
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a;
			maps[i][j] = a;
		}
	}
	for (int i = 0; i < 5; i++)
		cur.push_back(0);
	pq.push(cur);
	// cout << "pq.size : " << pq.size() << "\n";
	while (!pq.empty())
	{
		cur = pq.top();
		// cout << "=====  cur : " << cur[0] << " " << cur[1] << " " << cur[2] << " " << cur[3] << " " << cur[4] << "  =====\n";
		pq.pop();
		// if (visit[cur[1]][cur[2]][cur[3]][cur[4]]) continue ;
		visit[cur[1]][cur[2]][cur[3]][cur[4]] = 1;
		for (int dir = 0; dir < 4; dir++)
		{
			nextv.clear();
			nextv.push_back(cur[0] - 1);
			if (cur[3] == dir)
			{
				int		nextx = cur[1] + dx[dir] * (cur[4] + 1);
				int		nexty = cur[2] + dy[dir] * (cur[4] + 1);
				if (is_valid(nextx, nexty) == 0) continue ;
				int		flag = 0;
				// cout << "nextx, nexty, dir : " << nextx << " " << nexty << " " << dir << "\n";
				for (int i = cur[1] + 1; i < nextx; i++)
				{
					if (maps[i][cur[2]] != 0 && -nextv[0] > maps[i][cur[2]])
					{
						flag = 1;
						break ;
					}
				}
				for (int i = cur[2] + 1; i < nexty; i++)
				{
					if (maps[cur[1]][i] != 0 && -nextv[0] > maps[cur[1]][i])
					{
						flag = 1;
						break ;
					}
				}
				if (flag) continue ;
				// cout << "can pass road\n";
				if (maps[nextx][nexty] != 0 && -nextv[0] >= maps[nextx][nexty])
					continue ;
				// cout << "can arrive road\n";
				if (nextx == n - 1 && nexty == n - 1)
				{
					done = 1;
					break ;
				}
				// cout << "nextx, nexty, dir, cur[4] + 1 : " << nextx << " " << nexty << " " << dir << " " << cur[4] + 1<<"\n";
				// cout << "visit : " << visit[nextx][nexty][dir][cur[4] + 1]<< "\n";
				if (visit[nextx][nexty][dir][cur[4] + 1]) // visit check
					continue ;
				else visit[nextx][nexty][dir][cur[4] + 1] = 1;
				// cout << "push if!!\n";
				nextv.push_back(nextx);
				nextv.push_back(nexty);
				nextv.push_back(dir);
				nextv.push_back(cur[4] + 1);
				// cout << "nextv : " << nextv[0] << " " << nextv[1] << " " << nextv[2] << " " << nextv[3] << " " << nextv[4] << "\n";
				pq.push(nextv);
			}
			else
			{
				int		nextx = cur[1] + dx[dir];
				int		nexty = cur[2] + dy[dir];
				if (is_valid(nextx, nexty) == 0) continue ;
				// cout << "nextx, nexty, dir : " << nextx << " " << nexty << " " << dir << "\n";
				if (maps[nextx][nexty] != 0 && -nextv[0] >= maps[nextx][nexty])
					continue ;
				if (nextx == n - 1 && nexty == n - 1)
				{
					done = 1;
					break ;
				}
				// cout << "if not push, cannot visit\n";
				// cout << "visit : " << visit[nextx][nexty][dir][1] << "\n";
				if (visit[nextx][nexty][dir][1]) // visit check
					continue ;
				else visit[nextx][nexty][dir][1] = 1;
				// cout << "nextx, nexty, dir, 1 : " << nextx << " " << nexty << " " << dir << " " << 1 <<"\n";
				// cout << "push else!!\n";
				nextv.push_back(nextx);
				nextv.push_back(nexty);
				nextv.push_back(dir);
				nextv.push_back(1);
				// cout << "Size : " << nextv.size() << "\n";
				// cout << "nextv : " << nextv[0] << " " << nextv[1] << " " << nextv[2] << " " << nextv[3] << " " << nextv[4] << "\n";
				pq.push(nextv);
			}
		}
		if (done) break ;
	}
	if (done)
		cout << -cur[0] + 1;
	else cout << "Fired";
	return (0);
}