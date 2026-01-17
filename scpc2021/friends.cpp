#include <iostream>

using namespace std;

int		n, cur;
int		group = 1;
int		set_group[100001];
int		d[100001];

void	dfs(int cur)
{
	int		next = cur + d[cur];

	if (next > n)
	{
		set_group[cur] = group;
		group++;
		return ;
	}
	if (set_group[next] != 0)
	{
		set_group[cur] = set_group[next];
		return ;
	}
	else
		dfs(next);
	set_group[cur] = set_group[next];
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		T, test_case;
	
	// freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		group = 1;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			set_group[i] = 0;
			cin >> d[i];
		}
		for (int i = 1; i <= n; i++)
		{
			cur = i;
			if (set_group[cur] != 0)
				continue ;
			dfs(cur);
		}
		cout << "Case #" << test_case + 1 << "\n" << group - 1 << "\n";
	}
	return (0);
}
