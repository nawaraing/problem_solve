#include <iostream>
#include <cstring>

using namespace std;

string			str[2];//[100001];		//	[ 0 : cnt ][ start 0 1 ]
string			input[2];//[100001];
int				cnt[2];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	char		c;
	int			n;
	cin >> n;
	cin >> input[0] >> input[1];
	str[0] = str[1] = input[0];
	// cout << "input : " << input[1] << "\n";
	cnt[1]++;
	if (str[1][0] == '0') str[1][0] = '1';
	else str[1][0] = '0';
	if (str[1][1] == '0') str[1][1] = '1';
	else str[1][1] = '0';
	for (int i = 0; i < n - 2; i++)
	{
		if (str[0][i] != input[1][i])
		{
			cnt[0]++;
			if (str[0][i] == '0') str[0][i] = '1';
			else str[0][i] = '0';
			if (str[0][i + 1] == '0') str[0][i + 1] = '1';
			else str[0][i + 1] = '0';
			if (str[0][i + 2] == '0') str[0][i + 2] = '1';
			else str[0][i + 2] = '0';
		}
		if (str[1][i] != input[1][i])
		{
			cnt[1]++;
			if (str[1][i] == '0') str[1][i] = '1';
			else str[1][i] = '0';
			if (str[1][i + 1] == '0') str[1][i + 1] = '1';
			else str[1][i + 1] = '0';
			if (str[1][i + 2] == '0') str[1][i + 2] = '1';
			else str[1][i + 2] = '0';
		}
	}
	if (str[0][n - 2] != input[1][n - 2])
	{
		cnt[0]++;
		if (str[0][n - 2] == '0') str[0][n - 2] = '1';
		else str[0][n - 2] = '0';
		if (str[0][n - 1] == '0') str[0][n - 1] = '1';
		else str[0][n - 1] = '0';
	}
	if (str[1][n - 2] != input[1][n - 2])
	{
		cnt[1]++;
		if (str[1][n - 2] == '0') str[1][n - 2] = '1';
		else str[1][n - 2] = '0';
		if (str[1][n - 1] == '0') str[1][n - 1] = '1';
		else str[1][n - 1] = '0';
	}
	if (str[0][n - 1] == input[1][n - 1] && str[1][n - 1] == input[1][n - 1])
	{
		if (cnt[0] < cnt[1]) cout << cnt[0];
		else cout << cnt[1];
	}
	else if (str[0][n - 1] == input[1][n - 1])
		cout << cnt[0];
	else if (str[1][n - 1] == input[1][n - 1])
		cout << cnt[1];
	else cout << -1;
	return (0);
}