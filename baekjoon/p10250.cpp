#include <iostream>

/*
* Problem
*
* Ideas
*     n번째 손님을 층 수로 나눈 (나머지)층에 (몫+1)호수이다
*
* Comments
*/

using namespace std;

int main() {
	int		w, h, n, t, floor, room;

	cin >> t;
	for (int iT=0 ; iT<t ; iT++) {
		cin >> h >> w >> n;

		floor = n%h*100;
		if (!floor) floor = h*100;

		if (!(n%h)) room = n/h;
		else room = n/h + 1;
		cout << floor + room << "\n";
	}
}