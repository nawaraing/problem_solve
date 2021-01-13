#include <iostream>

using namespace std;

void	ft_recur(int n) {
	if (n == 3) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1) cout <<" ";
				else cout << "*";
			}
			cout << "\n";
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1) {
					 for (int k = 0; k < n / 3; k++) {
						 for (int l = 0; l < n /3; l++) {
							 cout << " ";
						 }
						 cout << "\n";
					 }
				}
				else ft_recur(n / 3);
			}
			cout << "\n";
		}
	}
	return ;
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int				n;

	cin >> n;
	ft_recur(n);
	return (0);
}
