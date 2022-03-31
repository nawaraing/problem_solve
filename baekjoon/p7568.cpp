#include <iostream>

/*
* Problem
*     https://www.acmicpc.net/problem/7568
*
* Ideas
*
* Comments
*/

using namespace std;

int		body[50][2]; // 0: weight  1: height

int main() {
	int			n, ans=0;

	cin >> n;
	for (int iN=0 ; iN<n ; iN++) cin >> body[iN][0] >> body[iN][1];
	for (int iA=0 ; iA<n ; iA++) {
		for (int iB=0 ; iB<n ; iB++) {
			if (body[iA][0] < body[iB][0] && body[iA][1] < body[iB][1]) ans++;
		}
		cout << ans + 1 << " ";
		ans=0;
	}
}