#include <iostream>
#include <queue>

using namespace std;

int		t, n, m, k, a;
int									player_cnt[100001];
priority_queue<pair<int, int> >		cnt_player;
priority_queue<pair<int, int> >		minus_cnt_days[100001];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> k;
			for (int j = 0; j < k; j++)
			{
				cin >> a;
				player_cnt[a]++;
			}
			
		}
		for (int i = 1; i <= n; i++)
			cnt_player.push(make_pair(player_cnt[i], i));
		
	}

	return (0);
}
