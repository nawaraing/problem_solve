#include <iostream>
#include <vector>

using namespace std;

int		n, m;
int		use[9];
vector<int>		v;

void	ft_backtracking(int cur)
{
	if (cur == m)
	{
		for (unsigned int i = 0; i < v.size(); i++)
		{
			cout << v[i];
			if (i != v.size() - 1)
				cout << " ";
			else
				cout << "\n";
		}
		return ;
	}

	for (int i = 1; i <= n; i++)
	{
		if (use[i]) continue ;
		v.push_back(i);
		use[i] = 1;
		ft_backtracking(cur + 1);
		v.pop_back();
		use[i] = 0;
	}
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	ft_backtracking(0);
	return (0);
}