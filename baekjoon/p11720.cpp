#include <iostream>

/*
* Problem
*     공백없이 쓰여진 n개의 숫자를 모두 더한 값을 출력하여라
*
* Ideas
*     cin으로 한 번에 받아서 for문을 돌리자
*
* Comments
*/

using namespace std;

int main() {
	int		n, sum=0;
	string	nums;

	cin >> n >> nums;
	for (int i=0 ; i<n ; i++) { 
		sum += nums[i] - '0';
	}
	cout << sum;
}