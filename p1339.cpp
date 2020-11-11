#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>			v[26];
string				str;
int					n;

bool	ft_sort(const vector<int> a, const vector<int> b) {
	int			sum1 = 0, sum2 = 0;

	for (int i = 0; i < 8; i++) {
		sum1 += sum1 * 10 + a[i];
		sum2 += sum2 * 10 + b[i];
	}
	return (sum1 > sum2);
}

bool	ft_int_sort(int a, int b) {return (a > b);}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		sum = 0, num[10];

	cin >> n;
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 8; j++)
			v[i].push_back(0);
	while (n--) {
		cin >> str;
		for (int i = 0; i < (int)str.length(); i++)
			v[str[i] - 'A'][8 - (int)str.length() + i]++;
	}
	for (int i = 0; i < 10; i++) num[i] = 0;
	sort(v, v + 26, ft_sort);
	for (int j = 0; j < 8; j++)
		for (int i = 0; i < 10; i++)
			num[i] = num[i] * 10 + v[i][j];
	sort(num, num + 10);
	for (int i = 0; i < 10; i++)
		sum += num[i] * i;
	cout << sum;
	return (0);
}