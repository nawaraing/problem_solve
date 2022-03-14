#include <iostream>
#include <stdio.h>

/*
* Problem
*     반 학생들의 점수가 주어진다
*     평균을 넘는 학생들의 비율을 소수점 셋째자리까지 구하여라
*
* Ideas
*     정직하게 구현하자
*
* Comments
*/

using namespace std;

int main() {
	int n, over=0;
	float num, sum=0, score, scores[1000], avg=0;

	cin >> n;
	for (int i=0 ; i<n ; i++) {
		cin >> num;
		for (int j=0 ; j<num ; j++) {
			cin >> score;
			scores[j] = score;
			sum += score;
		}
		avg = sum / num;
		for (int j=0 ; j<num ; j++) {
			if (scores[j] > avg) over++;
		}
		printf("%.3f%%\n", over/num*100);
		sum=0; over=0;
	}
}