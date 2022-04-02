#include <iostream>
#include <queue>
#include <cmath>

/*
* Problem
*     https://www.acmicpc.net/problem/2108
*
* Ideas
*
* Comments
*/

using namespace std;

#define SHIFT 4000

int							counts[8001];

int main() {
	priority_queue<int>		pq, ppq;
	int						n, num, sum=0, middle=0, minn=0, maxi=0, many=0;

	cin >> n;
	for (int iN=0 ; iN<n ; iN++) { cin >> num ; pq.push(num) ;}
	// cout << "pq size: " << pq.size() << "\n";
	// 	cout << "num: "; 
	while (!pq.empty()) {
		num = pq.top();
		// cout << num << " ";
		if (pq.size() == n) maxi = num;
		if (pq.size() == 1) minn = num;
		if (pq.size() == n/2+1) middle = num;

		counts[num + SHIFT]++;
		sum += num;
		pq.pop();
	}
	// cout << "\nmaxi: " << maxi << "\nminn: " << minn << "\nmiddle: " << middle << "\nsum: " << sum << "\n";
	// 산술평균
	int		pad = sum;
	if (sum >= 0) pad = 1;
	else pad = -1;
	if (abs(sum%n) <= n/2) cout << sum / n << "\n";
	else cout << sum / n + pad << "\n";
	// 중앙값
	cout << middle << "\n";
	// 최빈값
	// cout << "iCount: ";
	for (int iCount = -4000 ; iCount <= 4000 ; iCount++) {
		// cout << iCount << " ";
		if (many < counts[iCount + SHIFT]) {
			while (!ppq.empty()) ppq.pop();
			ppq.push(-iCount);
			many = counts[iCount + SHIFT];
		} else if (many == counts[iCount + SHIFT]) {
			ppq.push(-iCount);
		}
	}
	if (ppq.size() > 1) ppq.pop();
	cout << -ppq.top() << "\n";
	// 범위
	cout << maxi-minn;
}