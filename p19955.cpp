#include <iostream>
#include <vector>

using namespace std;

int			parent[1000001], map[2001][2001], n, m, q, xa, xb, ya, yb;

class game
{
	public:
	vector<vector<int> >	states;		// [num, army, terr]
	
	long long	strategy(int x, int y)
	{
		int		p = find(x, y);
	}
	battle();
	conscription(int days);
	expansion();

	private:
	int			find(int x, int y)
	{
		if (parent[map[x][y]] < 0)
			return (map[x][y]);
		int		tmp = find();
	}
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for(int i =0 ; i <= 1000000; i++) parent[i] = -1;

	return (0);
}