#include <iostream>
#include <queue>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int								n, a, b, end = 0, ret = 0;
	priority_queue<pair<int, int> >	pq;				//		<-end, -start>
	pair<int, int>					pr;

	cin >> n;
	while (n--) {
		cin >> a >> b;
		pq.push(make_pair(-b, -a));
	}
	while (pq.size()) {
		pr = pq.top();
		pq.pop();
		if (-pr.second < end) continue ;
		end = -pr.first;
		ret++;
	}
	cout << ret;
	return (0);
}