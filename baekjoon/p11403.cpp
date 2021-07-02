#include <iostream>

using namespace std;

int		graph[101][101];
int		n;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
			// cout << graph[i][j] << " ";
		}
		// cout << "\n";
	}
	for (int via = 0; via < n; via++)
	{
		for (int i = 0; i < n; i++)
		{
			if (via == i) continue ;
			for (int j = 0; j < n; j++)
			{
				if (via == j) continue ;
				if (graph[i][j]) continue ;
				if (graph[i][via] && graph[via][j])
					graph[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << graph[i][j];
			if (j != n - 1)
				cout << " ";
		}
		if (i != n - 1)
			cout << "\n";
	}
	return (0);
}