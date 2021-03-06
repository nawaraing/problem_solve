#include <iostream>
#include <vector>

using namespace std;

int				main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	unsigned long long		N, tmp1, tmp2;
	vector<unsigned long long>	nums(10);

	cin >> N;
	fill(nums.begin() + 1, nums.end(), 1);
	for (unsigned long long i = 1; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			tmp2 = nums[j];
			if (j == 0) nums[j] = nums[j + 1];
			else if (j == 9) nums[j] = tmp1;
			else {
				if (tmp1 + nums[j + 1] >= 1000000000)
					nums[j] = (tmp1 + nums[j + 1]) % 1000000000;
				else nums[j] = tmp1 + nums[j + 1];
			}
			tmp1 = tmp2;
		}
	}
	unsigned long long		ans = 0;
	for (int i = 0; i < 10; i++) ans += nums[i];
	ans = ans % 1000000000;
	cout << ans;
	return (0);
}
