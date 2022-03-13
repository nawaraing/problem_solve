#include <iostream>

/*
* Problem
*     현재 시각과 시간(분)이 주어질 때, 해당 시간 이후의 시각을 출력하라
*
* Ideas
*     현재 시각을 분 단위로 바꿔서 연산을 진행하고,
*     연산 후 시각이 24*60-1을 넘어갈 때, 24*60 만큼을 연산 시각에서 빼주겠다
*     그 이후에 단위를 (분->시간) 수정해준다
*     
* Comments
*/

using namespace std;

int main() {
	int h, m, total, need;

	cin >> h >> m >> need;
	total = h*60 + m + need;
	if (total >= 24*60) total -= 24*60;
	cout << total/60 << " " << total%60;
}