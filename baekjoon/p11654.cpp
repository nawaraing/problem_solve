#include <iostream>
#include <stdio.h>

/*
* Problem
*     알파벳 또는 0~9의 숫자가 주어질 때, 아스키코드 값으로 출력하여라
*
* Ideas
*     printf를 이용해 포매팅하자
*
* Comments
*/

using namespace std;

int main() {
	char	c;

	cin >> c;
	printf("%d", c);
}