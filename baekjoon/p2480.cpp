#include <iostream>

/*
* Problem
*     주사위 3개를 굴려서 아래 규칙과 같이 상금을 준다
*     1. 같은 눈이 3개가 나오면 10000+1000*(같은 눈)원의 상금을 준다
*     2. 같은 눈이 2개가 나오면 1000+100*(같은 눈)원의 상금을 준다
*     3. 모두 다른 눈이 나오면 (가장 큰 눈)*100원의 상금을 준다
*     3개의 주사위 눈이 입력으로 주어질 때, 주는 상금을 출력하라
*
* Ideas
*     주사위 갯수가 3개 밖에 안 되니까, 일일이 같은 주사위 눈이 몇 개인지 비교한다
*
* Comments
*/

using namespace std;

int main() {
	int a, b, c;

	cin >> a >> b >> c;

	if (a != b && b != c && c != a) {
		if (a > b && a > c)      cout << a*100;
		else if (b > c && b > a) cout << b*100;
		else if (c > a && c > b) cout << c*100;
		else cout << "error 1";
	} else if (a == b && b == c) {
		cout << 10000 + a*1000;
	} else {
		if (a == b || a == c) cout << 1000 + a*100;
		else if (b == c) cout << 1000 + b*100;
	}
}