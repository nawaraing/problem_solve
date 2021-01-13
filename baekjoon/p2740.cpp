#include <iostream>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		n, m, l, a, sum;

	cin >> n; cin >> m;
	int		matrix[n][m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a;
			matrix[i][j] = a;
		}
	}
	cin >> l; cin >> l;
	int		matrix2[m][l];

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < l; j++) {
			cin >> a;
			matrix2[i][j] = a;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < l; j++) {
			sum = 0;
			for (int k = 0; k < m; k++)
				sum += matrix[i][k] * matrix2[k][j];
			cout << sum;
			if (j != l - 1) cout << " ";
		}
		if (i != n - 1) cout << "\n";
	}
	return (0);
}
