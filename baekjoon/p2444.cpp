#include <iostream>

using namespace std;

void		ft_recur(int n, int i)
{
	for (int j = 0; j < n - i; j++) cout << " ";
	for (int j = 0; j < 2 * i - 1; j++) cout << "*";
	cout << "\n";
	if (i == n) return ;
	ft_recur(n, i + 1);
	for (int j = 0; j < n - i; j++) cout << " ";
	for (int j = 0; j < 2 * i - 1; j++) cout << "*";
	cout<<"\n";
	return ;
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		n;

	cin >> n;
	ft_recur(n, 1);
	return (0);
}
