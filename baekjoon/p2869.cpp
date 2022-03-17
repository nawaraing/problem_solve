#include <iostream>

/*
* Problem
*     달팽이가 V 높이의 나무막대를 올라간다
*     하룻동안 A만큼 올라갔다가 B만큼 내려오기를 반복한다
*     달팽이가 나무막대 꼭대기에 처음으로 도착하는데 걸리는 날 수를 구하여라
*
* Ideas
*     마지막 날에는 달팽이가 올라가서 내려오기 전에 꼭대기에 도착할 것이다
*     그래서 전체 높이에서 미리 A를 차감하고 걸린 날 수에 하루를 더한다
*     그리고 나머지 날 동안은 올라갔다 내려가기를 반복할테니
*     A-B만큼씩 올라갈 것이다
*
* Comments
*/

using namespace std;

int main() {
	int		up, down, high, ans=1;

	cin >> up >> down >> high;
	high -= up;
	up -= down;
	if (high%up == 0) ans += high / up;
	else ans += high / up + 1;

	cout << ans;
}