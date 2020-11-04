#include <iostream>
#include <math.h>

using namespace std;

long long		ft_ncr(long long n) {
	return (n * (n - 1) / 2);
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long		t, n, a, ret;
	long long		bina[32];
	long long		box[32];

	for (int i = 1; i <= 31; i++) {
		bina[i] = pow(2, i);
	}
	/*
	cout << "bina : ";
	for (int i = 1; i <= 31; i++) {
		cout << bina[i] << " ";
	}
	cout << "\n";
	*/
	cin >> t;
	while (t--) {
		cin >> n;
		if (n == 1) {
			cin >> a;
			cout << "0";
			if (t) cout << "\n";
			continue ;
		}
		ret = 0;
		for (int i = 1; i <= 31; i++) box[i] = 0;
		for (int i = 0; i < n; i++) {
			cin >> a;
			for (int j = 1; j <= 31; j++) {
				if (bina[j] > a) {
					box[j] += 1;
					break ;
				}
			}
		}
		for (int i = 1; i <= 31; i++) {
			if (box[i]) ret += ft_ncr(box[i]);
		}
		cout << ret;
		if (t) cout << "\n";
	}
	return (0);
}
