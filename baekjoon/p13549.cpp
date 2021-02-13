#include <stdio.h>
#include <deque>

using namespace std;

deque<pair<int, int>>	d; // cur , cnt
int				n, k, visit[100001];

int		main(void)
{
	scanf("%d %d", &n, &k);
	d.push_front(make_pair(n, 0));
	while (!d.empty())
	{
		pair<int, int>	pr = d.front();
		d.pop_front();
		if (pr.first == k) 
		{
			printf("%d", pr.second);
			break;
		}
		if (pr.first * 2 <= 100000 && visit[pr.first * 2] == 0)
		{
			visit[pr.first * 2] = 1;
			d.push_front(make_pair(pr.first * 2, pr.second));
		}
		if (pr.first + 1 <= 100000 && visit[pr.first + 1] == 0)
		{
			visit[pr.first + 1] = 1;
			d.push_back(make_pair(pr.first + 1, pr.second + 1));
		}
		if (pr.first - 1 >= 0 && visit[pr.first - 1] == 0)
		{
			visit[pr.first - 1] = 1;
			d.push_back(make_pair(pr.first - 1, pr.second + 1));
		}
	}
	return (0);
}