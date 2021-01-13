#include <iostream>
#include <stack>

using namespace std;

stack<int>	st, printable;

void			ft_recur()
{
	int		print_num;

	if (st.size() == 0) return ;
	while (printable.size() && st.top() >= printable.top()) printable.pop();
	if (printable.size() == 0) print_num = -1;
	else print_num = printable.top();
	printable.push(st.top());
	st.pop();
	ft_recur();
	cout << print_num << " ";
	return ;
}

int			main(void)
{
	int		N, A;

	cin >> N;
	while (N--) {
		cin >> A;
		st.push(A);
	}
	printable.push(st.top());
	st.pop();
	ft_recur();
	cout << "-1";
	return (0);
}
