#include <iostream>

using namespace std;

void		ft_recur(int n, int i)
{
	for (int j = 0; j < i; j++) cout << " ";
	for (int j = 0; j < 2 * (n - i) - 1; j++) cout << "*";
	cout << "\n";
	if (i == n - 1) return ;
	ft_recur(n, i + 1);
	for (int j = 0; j < i; j++) cout << " ";
	for (int j = 0; j < 2 * (n - i) - 1; j++) cout << "*";
	cout<<"\n";
	return ;
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		n;

	cin >> n;
	ft_recur(n, 0);
	return (0);
}
