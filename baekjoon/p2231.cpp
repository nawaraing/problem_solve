#include <iostream>

/*
* Problem
*
* Ideas
*     
* Comments
*/

using namespace std;

int main() {
	int		n, sum;

	cin >> n;
	for (int iN=0 ; iN<n ; iN++) {
		sum = iN;
		sum += iN%10;
		sum += iN/10%10;
		sum += iN/100%10;
		sum += iN/1000%10;
		sum += iN/10000%10;
		sum += iN/100000%10;
		sum += iN/1000000%10;

		if (sum == n) { cout << iN ; return 0 ;}
	}
	cout << 0;
}