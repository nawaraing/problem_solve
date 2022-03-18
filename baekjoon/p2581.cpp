#include <iostream>
// #include <stdio.h>

/*
* Problem
*     두 자연수 m, n (<10000) 사이에 소수들의 합과 최솟값을 구하여라
*
* Ideas
*     에라토스테네스의 체로 소수를 구별하는 배열을 미리 만들어놓자
*
* Comments
*/

using namespace std;

int main() {
	int			m, n, minn=0, sum=0;
	bool		notPrime[10001]={false, };

	notPrime[1] = true;
	for (int iPrime=2 ; iPrime<=100 ; iPrime++) {
		if (notPrime[iPrime]) continue ;
		for (int i=2 ; iPrime*i <= 10000 ; i++) notPrime[iPrime*i] = true;
	}
	
	cin >> m >> n;
	for (int iPrime = m ; iPrime <= n ; iPrime++) {
		if (!notPrime[iPrime]) {
			if (minn == 0) minn = iPrime;
			sum += iPrime;
		}
	}
	if (minn != 0) cout << sum << "\n" << minn;
	else cout << -1;
}