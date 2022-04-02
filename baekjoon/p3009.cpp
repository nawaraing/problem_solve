#include <iostream>

/*
* Problem
*     https://www.acmicpc.net/problem/2108
*
* Ideas
*
*     각 좌표별로 두칸의 공간을 만들어놓는다
*     첫번째 값이 들어왔을 때, 첫번째 칸이 비어있으므로 채워넣는다
*     두번째 값이 들어왔을 때, 첫번째 칸의 값과 비교해서 같으면 첫번째 칸을 비운다
*     두번째 값이 들어왔을 때, 첫번째 칸의 값과 비교해서 다르면 두번째 칸에 넣는다
*     세번째 값이 들어왔을 때, 첫번째 칸이 비어있으면 넣는다
*                        첫번째 칸이 채워져있으면 첫번째 칸과 두번째 칸을 확인해서 같은 값이 있는 칸을 비운다
*     좌표별 칸에 남아있는 값을 출력한다
*
* Comments
*/

using namespace std;

int		main() {
	int		box[2][2]={-1, -1, -1, -1};	//	[0: x, 1: y][]
	int		x, y;

	cin >> box[0][0] >> box[1][0];
	cin >> box[0][1] >> box[1][1];
	if (box[0][0] == box[0][1]) { box[0][0] = -1 ; box[0][1] = -1 ;}
	if (box[1][0] == box[1][1]) { box[1][0] = -1 ; box[1][1] = -1 ;}

	cin >> x >> y;
	if (box[0][0] == -1) cout << x << " ";
	else if (box[0][0] == x) cout << box[0][1] << " ";
	else cout << box[0][0] << " ";
	if (box[1][0] == -1) cout << y;
	else if (box[1][0] == y) cout << box[1][1];
	else cout << box[1][0];

}