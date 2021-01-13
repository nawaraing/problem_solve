#include <iostream>
#include <cmath>

using namespace std;

int			n, m, tree[(1 << 18)], lazy[(1 << 18)], o, s, t;

void	propagate(int node, int start, int end)
{
	if (lazy[node])
	{
		tree[node] = end - start + 1 - tree[node];
		if (start != end)
		{
			lazy[2 * node] = !lazy[2 * node];
			lazy[2 * node + 1] = !lazy[2 * node + 1];
		}
		lazy[node] = 0;
	}
}

void	update(int node, int start, int end, int left, int right)
{
	propagate(node, start, end);
	if (right < start || end < left) return ;
	if (left <= start && end <= right)
	{
		tree[node] = end - start + 1 - tree[node];
		if (start != end)
		{
			lazy[2 * node] = !lazy[2 * node];
			lazy[2 * node + 1] = !lazy[2 * node + 1];
		}
		return ;
	}
	int		mid = (start + end) / 2;
	update(2 * node, start, mid, left, right);
	update(2 * node + 1, mid + 1, end, left, right);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int		query(int node, int start, int end, int left, int right)
{
	propagate(node, start, end);
	if (right < start || end < left) return (0);
	if (left <= start && end <= right) return tree[node];
	int		mid = (start + end) / 2;
	return (query(2 * node, start, mid, left, right) + query(2 * node + 1, mid + 1, end, left, right));
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> o >> s >> t;
		if (o == 0)
			update(1, 1, n, s, t);
		else
			cout << query(1, 1, n, s, t) << "\n";
	}
	return (0);
}