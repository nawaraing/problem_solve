#include <iostream>
#include <vector>

/*
* Problem
*     정수 n이 주어졌을 때, 소인수분해하는 프로그램을 작성하시오
*     https://www.acmicpc.net/problem/11653
*
* Ideas
*     에라토스테네스의 체로 소수를 구별하는 배열을 미리 만들어놓자
*     그리고 그 소수들로 나누어지는 지 확인하자
*
*
* Comments
*     에라토스테네스의 체를 이용할 때, 루트 n만큼만 확인을 하면 된다
*     그런데 그렇게하니까, 벡터에 모든 소수를 넣을 수 없는 문제가 발생했다
*     그래서 루트 n까지의 소수로 나누어 떨어지지 않는 수는 소수라고 생각했다 (line 45)
*     
*     코드영역에 선언한 배열은 백만mb가 최대사이즈이다 (스택 영역)
*     그래서 세그펄트가 발생해서 전역변수로 선언했다 (데이터 영역)
*/

using namespace std;

bool		notPrime[10000001];

int main() {
	int			n, p;
	vector<int>	prime;

	notPrime[1] = true;
	for (int iPrime=2 ; iPrime<=10000 ; iPrime++) {
		if (notPrime[iPrime]) continue ;
		prime.push_back(iPrime);
		for (int i=2 ; iPrime*i <= 10000000 ; i++) notPrime[iPrime*i] = true;
	}

	cin >> n;
	if (n == 1) return 0;
	for (int iPrime=0 ; iPrime < prime.size() ; iPrime++) {
		p = prime[iPrime];
		while (n%p == 0) { n /= p ; cout << p << "\n" ;}
		if (n == 1) break ;
	}
	if (n != 1) {cout << n ;}
}