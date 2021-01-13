#include <iostream>
#include <cmath>

using namespace std;

int				nums[20];
int				cnt;

void	ft_backtracking(int n, int s, int idx, bool v[20]) {
	int			sum = 0;
/*
	for (int i = 0; i < 20; i++) cout << " " << v[i];
	cout << "\n";
*/
	if (n == idx) {
		for (int i = 0; i < n; i++) {
			if (v[i]) sum += nums[i];
		}
		if (sum == s) cnt++;
		return ;
	}
	ft_backtracking(n, s, idx + 1, v);
	v[idx] = 1;
	ft_backtracking(n, s, idx + 1, v);
	v[idx] = 0;
	return ;
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int				n, s, a;
	bool			v[20];

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a;
		nums[i] = a;
	}
	for (int i = 0; i < n; i++) {
		v[i] = 0;
	} 
	ft_backtracking(n, s, 0, v);
	if (s == 0) cout << cnt - 1;
	else cout << cnt;
	return (0);
 }
