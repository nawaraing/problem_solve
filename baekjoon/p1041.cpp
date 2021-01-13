#include <iostream>
#include <limits.h>

using namespace std;

long long				n, dice[7], least[4];

void	ft_make_least(void) {
	// * 1-surface is least value
	for (int i = 1; i <= 6; i++) {
		if (least[1] > dice[i]) least[1] = dice[i];
	}
	// * 2-surface is least value
	if (least[2] > dice[1] + dice[2]) least[2] = dice[1] + dice[2];
	if (least[2] > dice[1] + dice[3]) least[2] = dice[1] + dice[3];
	if (least[2] > dice[1] + dice[4]) least[2] = dice[1] + dice[4];
	if (least[2] > dice[1] + dice[5]) least[2] = dice[1] + dice[5];
	if (least[2] > dice[6] + dice[2]) least[2] = dice[6] + dice[2];
	if (least[2] > dice[6] + dice[3]) least[2] = dice[6] + dice[3];
	if (least[2] > dice[6] + dice[4]) least[2] = dice[6] + dice[4];
	if (least[2] > dice[6] + dice[5]) least[2] = dice[6] + dice[5];
	if (least[2] > dice[3] + dice[2]) least[2] = dice[3] + dice[2];
	if (least[2] > dice[5] + dice[3]) least[2] = dice[5] + dice[3];
	if (least[2] > dice[5] + dice[4]) least[2] = dice[5] + dice[4];
	if (least[2] > dice[4] + dice[2]) least[2] = dice[4] + dice[2];
	// * 3-surface is least value
	if (least[3] > dice[1] + dice[2] + dice[3]) least[3] = dice[1] + dice[2] + dice[3];
	if (least[3] > dice[1] + dice[5] + dice[3]) least[3] = dice[1] + dice[5] + dice[3];
	if (least[3] > dice[1] + dice[4] + dice[5]) least[3] = dice[1] + dice[4] + dice[5];
	if (least[3] > dice[1] + dice[2] + dice[4]) least[3] = dice[1] + dice[2] + dice[4];
	if (least[3] > dice[6] + dice[2] + dice[3]) least[3] = dice[6] + dice[2] + dice[3];
	if (least[3] > dice[6] + dice[5] + dice[3]) least[3] = dice[6] + dice[5] + dice[3];
	if (least[3] > dice[6] + dice[4] + dice[5]) least[3] = dice[6] + dice[4] + dice[5];
	if (least[3] > dice[6] + dice[2] + dice[4]) least[3] = dice[6] + dice[2] + dice[4];
}

long long		ft_calcul(void) {
	long long			ret = 0;

	ret += ((n - 2) * (5 * n - 6)) * least[1];
	ret += (8 * n - 12) * least[2];
	ret += 4 * least[3];
	return (ret);
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= 6; i++) {
		cin >> dice[i];
		if (i < 4) least[i] = LLONG_MAX;
	}
	if (n == 1) {
		int maxi = 0;
		int	sum = 0;
		for (int i = 1; i <= 6; i++) {
			sum += dice[i];
			if (maxi < dice[i]) maxi = dice[i];
		}
		sum -= maxi;
		cout << sum;
		return (0);
	}
	ft_make_least();
//	for (int i = 1; i <= 3; i++) cout << least[i] << "\n";
	if (n == 2) {
		int ret = 0;
		ret += 4 * least[3];
		ret += 4 * least[2];
		cout << ret;
		return (0);
	}
	cout << ft_calcul();
	return (0);
}