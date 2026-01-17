#include <iostream>

using namespace std;

int t, k, n;
int apart[15][15];
// k층 i호

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 0층
	for (int i = 1; i <= 14; i++) {
		apart[0][i] = i;
	}

	//
	for (int i = 1; i <= 14; i++) {
		for (int j = 1; j <= 14; j++) {
			int sum = 0;
			for (int tmp = 1; tmp <= j; tmp++) {
				sum += apart[i - 1][tmp];
			}
			apart[i][j] = sum;
		}
	}

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> k >> n;
		cout << apart[k][n] << "\n";
	}
}