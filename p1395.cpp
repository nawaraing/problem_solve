#include <iostream>
#include <cmath>

using namespace std;

int		make_full(int digit)
{
	return ((1 << digit) - 1);
}

int		change(int num, int digit)
{
	return (num ^ make_full(digit));
}

int		merge(int a, int b, int digit)
{
	return ((a << digit) | b);
}

int		tree[(1 << 18)], lazy[(1 << 18)], n, m, o, s, t;

void		propagation(int	node, int start, int end)
{
	if (lazy[node] == 0 || lazy[node] % 2 == 0) return ;
	tree[node] = change(tree[node], end - start + 1);
	if (start != end)
	{
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}

int				query(int node, int start, int end, int left, int right)
{
	cout << "query\ntree : ";
	for (int i = 1; i <= 7; i++)
		cout << tree[i] << " ";
	cout << "\n";
	cout << "lazy : ";
	for (int i = 1; i <= 7; i++)
		cout << lazy[i] << " ";
	cout << "\n";
	cout << node << " " << start << " "<< end << " " << left << " "<< right<< "\n";
	propagation(node, start, end);
	if (right < start || end < left) return (0);
	if (left <= start && end <= right) return (tree[node]);
	int		mid = (start + end) / 2;
	return ((tree[node] = merge(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right), end - mid)));
}

void			update(int node, int start, int end, int left, int right)
{
	cout << "tree : ";
	for (int i = 1; i <= 7; i++)
		cout << tree[i] << " ";
	cout << "\n";
	cout << "lazy : ";
	for (int i = 1; i <= 7; i++)
		cout << lazy[i] << " ";
	cout << "\n";
	cout << node << " " << start << " "<< end << " " << left << " "<< right<< "\n";
	propagation(node, start, end);
	if (right < start || end < left) return ;
	if (left <= start && end <= right) {
		tree[node] = change(tree[node], end - start + 1);
		if (start != end)
		{
			lazy[node * 2] += 1;
			lazy[node * 2 + 1] += 1;
		}
		return ;
	}
	int		mid = (start + end) / 2;
	update(node * 2, start, mid, left, right);
	update(node * 2 + 1, mid + 1, end, left, right);
	tree[node] = merge(tree[node * 2], tree[node * 2 + 1], end - mid);
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i =0; i < m; i++)
	{
		cin >> o >> s>> t;
		if (o == 0) update(1, 0, n - 1, s - 1, t - 1);
		else cout << query(1, 0, n - 1, s - 1, t - 1) << "\n";
	}
	return (0);
}