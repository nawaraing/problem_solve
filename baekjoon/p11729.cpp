#include <iostream>

/*
* Problem
*
* Ideas
*
* Comments
*/

using namespace std;

void	hanoi(int n, int start, int end) {
	if (n == 1) { cout << start << " " << end << "\n" ; return ;}

	hanoi(n - 1, start, 6 - start - end);
	cout << start << " " << end << "\n";
	hanoi(n - 1, 6 - start - end, end);
}

int main() {
	int	n, cnt = 1;

	cin >> n;
	for (int iN=1 ; iN<n ; iN++) cnt = 2*cnt + 1;
	cout << cnt << "\n";
	hanoi(n, 1, 3);
}