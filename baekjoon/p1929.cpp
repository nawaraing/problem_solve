#include <iostream>

/*
* Problem
*     자연수 m, n이 주어졌을 때, m이상 n이하의 소수를 순서대로 출력하여라
*     https://www.acmicpc.net/problem/1929
*
* Ideas
*     에라토스테네스의 체를 이용하자
*
* Comments
*/

using namespace std;


int main() {
	int			m, n;
	bool		notPrime[1000001];

	cin >> m >> n;

	notPrime[1] = true;
	for (int iPrime=2 ; iPrime<=1000 ; iPrime++) {
		if (notPrime[iPrime]) continue ;
		if (iPrime >= m && iPrime <= n) cout << iPrime << "\n";
		for (int i=2 ; iPrime*i <= 1000000 ; i++) notPrime[iPrime*i] = true;
	}
	for (int iPrime=1001 ; iPrime<=1000000 ; iPrime++) {
		if (notPrime[iPrime]) continue ;
		if (iPrime >= m && iPrime <= n) cout << iPrime << "\n";
	}
}