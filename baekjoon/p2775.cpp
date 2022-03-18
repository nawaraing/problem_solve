#include <iostream>
// #include <stdio.h>

/*
* Problem
*
* Ideas
*     2x2 배열로 직접 계산하자
*
* Comments
*/

using namespace std;

int main() {
	int	apart[15][15]; // [floor][room num]
	int	t, f, n;

	for (int i=1 ; i<=14 ; i++) apart[0][i] = i;
	for (int iFloor=1 ; iFloor<=14 ; iFloor++) {
		for (int iRoom=1 ; iRoom<=14 ; iRoom++) {
			if (iRoom == 1) apart[iFloor][iRoom] = 1;
			else apart[iFloor][iRoom] = apart[iFloor-1][iRoom] + apart[iFloor][iRoom-1];
			// cout << apart[iFloor][iRoom] << " ";
			// printf(" %8d", apart[iFloor][iRoom]);
		}
		// cout << "\n";
	}

	cin >> t;
	for (int iT=0 ; iT<t ; iT++) {
		cin >> f >> n;
		cout << apart[f][n] << "\n";
	}
}