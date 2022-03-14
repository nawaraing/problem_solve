#include <iostream>

/*
* Problem
*     시험성적 n<=1000개가 입력으로 주어진다
*     각각의 성적을 수정할 것이다
*     수정하는 방법은 (각 시험성적)/(가장 높은 성적) * 100 이다
*     수정된 성적들로 평균을 구해서 10^-2이하의 오차범위로 출력하라
*
* Ideas
*     계산의 효율성을 위해서, 성적 수정과 평균을 구하는 식을 섞어서 연산을 시키겠다
*
* Comments
*/

using namespace std;

int main() {
	int n;
	float sum=0, score, maxi=0;

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> score;
		sum += score;
		if (maxi < score) maxi = score;
	}
	sum /= maxi;
	sum *= 100;
	sum /= (float)n;
	cout << sum;
}