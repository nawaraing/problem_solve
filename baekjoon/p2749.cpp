#include <iostream>
#include <queue>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	queue<unsigned long long>	q;
	unsigned long long			n, a;

	cin >> n;
	if (n == 0)
	{
		cout << "0";
		return (0);
	}
	else if (n == 1)
	{
		cout << "1";
		return (0);
	}
	q.push(0);
	q.push(1);
	n--;
	while (n--) {
//		cout << n << "\n";
		a = q.front();
		q.pop();
		a += q.front();
		a %= 1000000;
		q.push(a);
	}
	cout << q.back();
	return (0);
}