#include <iostream>

/*
* Problem
*
* Ideas
*     
* Comments
*/

using namespace std;

int main() {
	int		n, m, nums[101], sum, ans=0;

	cin >> n >> m;
	for (int iN=0 ; iN<n ; iN++) cin >> nums[iN];
	for (int iA=0 ; iA<n ; iA++) {
		for (int iB=iA+1 ; iB<n ; iB++) {
			for (int iC=iB+1 ; iC<n ; iC++) {
				sum = nums[iA] + nums[iB] + nums[iC];
				if (sum <= m && sum > ans) ans = sum;
			}
		}
	}
	cout << ans;
}