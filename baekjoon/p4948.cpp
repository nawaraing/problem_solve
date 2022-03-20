#include <iostream>

/*
* Problem
*     자연수 n(<=123456)이 주어졌을 때,
*     n 보다 크고 2n보다 작거나 같은 소수의 갯수를 출력하여라 
*     https://www.acmicpc.net/problem/4948
*
* Ideas
*     에라토스테네스의 체를 이용하자
*
* Comments
*     배열 초기화를 안 해줘서 한 번 틀림;;;
*/

using namespace std;

int main() {
	int			n, cnt=0;
	bool		notPrime[246913] = {false,};

	notPrime[1] = true;
	for (int iPrime=2 ; iPrime<=246912 ; iPrime++) {
		if (notPrime[iPrime]) continue ;
		for (int i=2 ; iPrime*i <= 246912 ; i++) notPrime[iPrime*i] = true;
	}
	while (1) { 
		cin >> n;
		if (!n) return 0;

		cnt = 0;
		for (int iPrime = n+1 ; iPrime <= 2*n ; iPrime++)
			if (!notPrime[iPrime]) cnt++;
		cout << cnt << "\n";
	}
}