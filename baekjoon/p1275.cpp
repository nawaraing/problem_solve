#include <iostream>
#include <cmath>

using namespace std;

int			n, q, x, y, a;
unsigned long long	b;
unsigned long long	arr[100000], tree[(1 << 18)];

long long 	init(int node, int start, int end)
{
	if (start == end)
		return ((tree[node] = arr[start]));
	int		mid = (start + end) / 2;
	return ((tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end)));
}

long long	summation(int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return (0);
	if (left <= start && end <= right) return (tree[node]);
	int		mid = (start + end) / 2;
	return (summation(node * 2, start, mid, left, right) + summation(node * 2 + 1, mid + 1, end, left, right));
}

long long	update(int node, int start, int end, int idx, int n)
{
	if (idx < start || idx > end) return (tree[node]);
	int		mid = (start + end) / 2;
	if (start == end)
		return ((tree[node] = n));
	return ((tree[node] = update(node * 2, start, mid, idx, n) + update(node * 2 + 1, mid + 1, end, idx, n)));
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> q;
	for (int i =0 ; i< n; i++) cin >> arr[i];
	init(1, 0, n - 1);
	for (int i = 0; i < q; i++)
	{
		cin >> x >> y>> a >>b;
		if (x > y)
		{
			int tmp = x;
			x = y;
			y = tmp;
		}
		cout << summation(1, 0, n - 1, x - 1, y - 1);
		if (i != q - 1) cout << "\n";
		update(1, 0, n - 1, a - 1, b);
	}
	return (0);
}