#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char			map[6][6];
int				n;
vector<int>		v;

void	dfs(int r, int c, int sum, char oper)
{
	if (map[r][c] >= '0' && map[r][c] <= '5')
	{
		if (oper == '*')
			sum *= map[r][c] - '0';
		else if (oper == '+')
			sum += map[r][c] - '0';
		else if (oper == '-')
			sum -= map[r][c] - '0';
		else if (oper == 0)
			sum = map[r][c] - '0';
		if (r + 1 < n) dfs(r + 1, c, sum, 0);
		if (c + 1 < n) dfs(r, c + 1, sum, 0);
	}
	else
	{
		if (r + 1 < n) dfs(r + 1, c, sum, map[r][c]);
		if (c + 1 < n) dfs(r, c + 1, sum, map[r][c]);
	}
	if (r == n - 1 && c == n - 1)
	{

		// cout << "sum : " << sum << "\n";
		v.push_back(sum);
	}
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i =0; i< n; i++)
	{
		for (int j = 0; j < n;j++)
		{
			cin >> map[i][j];
		}
	}
	dfs(0, 0, 0, 0);
	sort(v.begin(), v.end());
	cout << v[v.size() - 1] << " " << v[0];
	return (0);
}