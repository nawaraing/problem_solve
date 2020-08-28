#include <iostream>
#include <vector>

using namespace std;

int			main(void)
{
	int		p1, p2, n, a, max = 0;
	vector<int>	vctr;

	cin >> n;
	while (n--) {
		cin >> a;
		vctr.push_back(a);
	}
	for (int i = 0; i <= vctr.size(); i++) {
		p1 = 0;
		p2 = 0;
		for (int j = 0; j < vctr.size(); j++) {
			if (j < i)  p1 += vctr[j] * vctr[j];
			else p2 += vctr[j];
		}
		if (max < p1 * p2) max = p1 * p2;
	}
	cout << max;
	return (0);
}
