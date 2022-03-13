#include <iostream>

/*
* Problem
*     입력으로 주어지는 불기 연도를 서기 연도로 바꿔서 출력하라
*
* Ideas
*     불기와 서기의 차이를 검색해서 해결하겠다
*     
* Comments
*     블로그에서 544년만큼 차이난다고 확인했는데,
*     이 문제에서는 543을 뺀 것이 정답이다
*/

using namespace std;

int main() {
	int bud_year;

	cin >> bud_year;
	cout << bud_year-543;
}