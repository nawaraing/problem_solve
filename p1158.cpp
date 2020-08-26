#include <iostream>
#include <list>

using namespace std;

int		main(void)
{
	int			N, K;
	list<int>		table, ret;

	cin >> N;
	cin >> K;
	while (N--) table.push_front(N + 1);
	list<int>::iterator	iter = table.begin();
	cout << "<";
	while (table.size()) {
		if (iter == table.end()) iter = table.begin();
		for (int i = 0; i < K - 1; i++) {
			if (iter != table.end()) iter++;
			if (iter == table.end()) iter = table.begin();
		}
		cout << *iter;
		iter = table.erase(iter);
		if (table.size() != 0) cout << ", ";
	}
	cout << ">";
	return (0);
}
