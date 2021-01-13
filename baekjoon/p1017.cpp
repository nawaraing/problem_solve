#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int				n, a;
bool			check[2000], prime[2000];
int				use[2000];
vector<int>		graph[51], nums;

bool	ft_dfs(int idx) {
	for (int i = 0; i < nums.size(); i++) {
		if (!prime[nums[idx] + nums[i]] || idx == i) continue ;
		if (check[nums[i]]) continue ;
		check[nums[i]] = true;
		if (use[nums[i]] == 0 || ft_dfs(use[nums[i]])) {
			use[nums[i]] = nums[idx];
			use[nums[idx]] = nums[i];
			return (true);
		}
	}

}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 2000; i++) prime[i] = true;
	for (int i = 2; i < 2000; i++) {
		if (prime[i]) {
			for (int j = 2; i * j < 2000; j++) prime[i * j] = false;
		}
	}
	cin >> n;
	while (n--) {
		cin >> a;
		nums.push_back(a);
	}
	for (int i = 1; i <= nums.size(); i++) {
		for (int j = i + 1; j <= nums.size(); j++) {
			if (prime[nums[i] + nums[j]]) {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}
	for (int i = 1; i <= nums.size(); i++) {
		for (int j = 0; j < 2000; j++) check[j] = false;
		if (ft_dfs(i)) 
	}
	return (0);
}