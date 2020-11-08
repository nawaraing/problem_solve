#include <iostream>
#include <unistd.h>
#include <list>
#include <cstring>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string			str;
	char			ch;
	bool			flag = 0;
	list<char>		lst;
	int				num = 0, sum = 0;

	cin >> str;
	for (int i = 0; i < str.size(); i++)
		lst.push_back(str[i]);
	while (lst.size()) {
		ch = lst.front();
		lst.pop_front();
		if (!flag && (ch == '+' || ch == '-')) {
			sum += num;
			num = 0;
			if (ch == '-') flag = 1;
		}
		else if (flag && (ch == '+' || ch == '-')) {
			sum -= num;
			num = 0;
		}
		else
			num = num * 10 + ch - '0';
	}
	if (flag) sum -= num;
	else sum += num;
	cout << sum;
	return (0);
}