#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int				nums[1000001];
queue<int>		q;

void	ft_print(void) {
	int			cur = 1;
	stack<int>	st;
	int			cnt = 0;

	while (cur) {
		st.push(cur);
		cnt++;
		cur = nums[cur];
	}
	cout << cnt - 1 << "\n";
	while (st.size()) {
		cout << st.top();
		st.pop();
		if (st.size()) cout << " ";
	}
	return ;
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int			n;
	cin >> n;
	q.push(n);
	while (q.size()) {
		int			cur = q.front();
		q.pop();

		if (cur == 1) break ;
		if (!(cur % 3) && !nums[cur / 3]) {
			q.push(cur / 3);
			nums[cur / 3] = cur;
		}
		if (!(cur % 2) && !nums[cur / 2]) {
			q.push(cur / 2);
			nums[cur / 2] = cur;
		}
		if (!nums[cur - 1]) {
			q.push(cur - 1);
			nums[cur - 1] = cur;
		}
	}
	ft_print();
	return (0);
}