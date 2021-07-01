#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int		paper[101][101];
int		n, m, k;
int		x1, y1, x2, y2;
int		dx[4] = {1, -1, 0, 0};
int		dy[4] = {0, 0, 1, -1};
vector<int>		aria;
queue<pair<int, int> >		q;

void	ft_bfs(int x, int y)
{
	int		aaria = 1;

	q.push(make_pair(x, y));
	while (!q.empty())
	{
		pair<int, int>	pr = q.front();
		q.pop();
		paper[pr.first][pr.second] = 1;
		for (int i = 0; i < 4; i++)
		{
			int		nextx = pr.first + dx[i];
			int		nexty = pr.second + dy[i];

			if (nextx < 0 || nextx >= n) continue ;
			if (nexty < 0 || nexty >= m) continue ;
			if (paper[nextx][nexty]) continue ;
			paper[nextx][nexty] = 1;
			aaria++;
			// cout << "nextx: " << nextx << "   nexty: " << nexty << endl;
			q.push(make_pair(nextx, nexty));
		}
	}
	// cout << "aaria: " << aaria<< endl;
	aria.push_back(aaria);
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> m >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		
		for (int wid = x1; wid < x2; wid++)
		{
			for (int hei = y1; hei < y2; hei++)
			{
				paper[wid][hei] = 1;
			}
		}
	}
	// for (int j = 0; j < m; j++)
	// {
	// 	for (int i  =0 ; i < n; i++)
	// 	{
	// 		cout << paper[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (paper[i][j]) continue ;
			ft_bfs(i, j);
		}
	}
	sort(aria.begin(), aria.end());
	// cout << "v size : " << aria.size() << endl;
	cout <<  aria.size() << endl;
	for (unsigned int i = 0; i < aria.size(); i++)
	{
		cout << aria[i];
		if (i != aria.size() - 1)
			cout << " ";
	}
	return (0);
}