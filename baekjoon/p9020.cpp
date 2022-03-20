#include <iostream>

/*
* Problem
*     짝수 (4<=)n(<=10000)이 주어질 때, 두 소수의 합으로 나타내어라
*     여러 개일 때는 두 소수의 차이가 가장 작은 것을 출력한다
*     https://www.acmicpc.net/problem/9020
*
* Ideas
*     에라토스테네스의 체를 이용하자
*
* Comments
*     에라토스테네스 체 코드를 복붙하다보니 실수를 했다
*     define을 써서 수정을 쉽게 코드를 작성하자
*/

using namespace std;

#define PRIME_SIZE 10000

int main() {
	int			t, n;
	bool		notPrime[PRIME_SIZE + 1] = {false, };

	notPrime[1] = true;
	for (int iPrime=2 ; iPrime<=100 ; iPrime++) {
		if (notPrime[iPrime]) continue ;
		for (int i=2 ; iPrime*i <= PRIME_SIZE ; i++) notPrime[iPrime*i] = true;
	}
	cin >> t;
	for (int iT=0 ; iT<t ; iT++) {
		cin >> n;
		for (int iPrime=n/2 ; iPrime >= 2 ; iPrime--) {
			if (!notPrime[iPrime] && !notPrime[n - iPrime]) {
				cout << iPrime << " " << n-iPrime << "\n";
				break ;
			}
		}
	}
}