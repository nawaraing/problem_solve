#include <iostream>
#include <cmath>

using namespace std;

int			n, m, cmd, a, b, c, tree[(1 << 20)], lazy[(1 << 20)], arr[500000 + 1];

void	init(int node, int start, int end)
{
	if (start == end) {
		tree[node] = arr[start];
		return ;
	}
	int		mid = (start + end) / 2;
	init(2 * node, start, mid);
	init(2 * node + 1, mid + 1, end);
	tree[node] = tree[2 * node] ^ tree[2 * node + 1];
}

void	propagation(int node, int start, int end)
{
	if (lazy[node])
	{
		if ((end - start + 1) % 2) tree[node] ^= lazy[node];
		if (start != end)
		{
			lazy[2 * node] ^= lazy[node];
			lazy[2 * node + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

void		update(int node, int start, int end, int left, int right, int xo)
{
	// cout << "update : " << node << " " << start << " " << end << " " << left << " " << right << " " << xo << "\n";
	propagation(node, start, end);
	if (right < start || end < left) return ;
	if (left <= start && end <= right)
	{
		if ((end - start + 1) % 2) tree[node] ^= xo;
		if (start != end)
		{
			lazy[2 * node] ^= xo;
			lazy[2 * node + 1] ^= xo;
		}
		return ;
	}
	int		mid = (start + end) / 2;
	update(2 * node, start, mid, left, right, xo);
	update(2 * node + 1, mid + 1, end, left, right, xo);
	tree[node] = tree[2 * node] ^ tree[2 * node + 1];
}

int		query(int node, int start, int end, int left, int right)
{
	propagation(node, start, end);
	if (right < start || end < left) return (0);
	if (left <= start && end <= right) return (tree[node]);
	int		mid = (start + end) / 2;
	return (query(2 * node, start, mid, left, right) ^ query(2 * node + 1, mid + 1, end, left, right));
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <=n ; i++)
	{
		cin >> a;
		arr[i] = a;
	}
	cin >> m;
	init(1, 1, n);
	// cout << "\ntree : ";
	// for (int i = 1; i <= 9; i++) cout << tree[i] << " ";
	// cout << "\n";
	while (m--)
	{
		cin >> cmd >> a >> b;
/* 		if (a > b)
		{
			int tmp = a;
			a = b;
			b = tmp;
		}
 */		if (cmd == 1)
		{
			cin >> c;
			update(1, 0, n - 1, a, b, c);
		}
		else
			cout << query(1, 0, n - 1, a, b) << "\n";
		// cout << "\ntree : ";
		// for (int i = 1; i <= 9; i++) cout << tree[i] << " ";
		// cout << "\n";
	}
	return (0);
}