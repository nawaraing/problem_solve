#include <iostream>
#include <vector>

using namespace std;

int				main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		N, tmp1, tmp2;
	vector<int>	nums(10);

	cin >> N;
	fill(nums.begin() + 1, nums.end(), 1);
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			tmp2 = nums[j];
			if (j == 0) nums[j] = nums[j + 1];
			else if (j == 9) nums[j] = tmp1;
			else {
				tmp2 = nums[j];
				nums[j] = tmp1 + nums[j + 1];
				tmp1= tmp2;
			}
			tmp1 = tmp2;
		}
	}
	int		ans = 0;
	for (int i = 0; i < 10; i++) ans += nums[i];
	cout << ans;
	return (0);
}
