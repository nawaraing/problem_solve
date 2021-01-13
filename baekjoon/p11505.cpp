#include <iostream>
#include <cmath>

using namespace std;

long long			tree[(1 << 21)], nums[1000000];
int			n, m, k, a, b, c;

long long		init(int node, int start, int end)
{
	if (start == end)
		return ((tree[node] = nums[start]));
	int		mid = (start + end) / 2;
	tree[node] = init(node * 2, start, mid) * init(node * 2 + 1, mid + 1, end);
	if (tree[node] > 1000000007) tree[node] %= 1000000007;
	return (tree[node]);
}

long long		update(int node, int start, int end, int idx, int n)
{
	if (idx < start || idx > end) return (tree[node]);
	if (start == end)
		return ((tree[node] = n));
	int		mid = (start + end) / 2;
	tree[node] = update(node * 2, start, mid, idx, n) * update(node * 2 + 1, mid + 1, end, idx, n);
	if (tree[node] > 1000000007) tree[node] %= 1000000007;
	return (tree[node]);
}

long long		multi_is(int node, int start, int end, int left, int right)
{
	// cout << start << " "<< end <<" "<< left<<" " << right<<" " << node<< "\n";
	if (right < start || end < left) return (1);

	if (left <= start && end <= right) return (tree[node]);

	int			mid = (start + end) / 2;
	long long	tmp = multi_is(node * 2, start, mid, left, right) * multi_is(node * 2 + 1, mid + 1, end, left, right);
	if (tmp > 1000000007) tmp %= 1000000007;
	return (tmp);
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	init(1, 0, n - 1);
	// cout << "init : ";
	// for (int i = 1 ; i <= 9; i++) cout << tree[i] << " ";
	// cout << "\n";
	for (int i = 0; i < m + k; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			update(1, 0, n - 1, b - 1, c);
			// cout << "init : ";
			// for (int i = 1 ; i <= 9; i++) cout << tree[i] << " ";
			// cout << "\n";
		}
		else
		{
			// cout << "start end left right\n";
			cout << multi_is(1, 0, n - 1, b - 1, c - 1) << "\n";
		}
	}
	return (0);
}