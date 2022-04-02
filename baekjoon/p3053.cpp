#include <iostream>
#include <stdio.h>

/*
* Problem
*     https://www.acmicpc.net/problem/3053
*
* Ideas
*
* Comments
*     정밀도 차이 때문에 float은 안 되고 double은 된다...왜지?
*/

using namespace std;

#define PI 3.1415926535897

int		main() {
	double		r;

	cin >> r;
	printf("%.6f\n%.6f", r * r * PI, r * r * 2);
}