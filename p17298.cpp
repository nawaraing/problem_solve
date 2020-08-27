#include <iostream>
#include <stack>

using namespace std;

void			ft_recur(stack<int> st, stack<int> printable)
{
	if (st.size() == 0) return ;

	int		print_num;

	while (printable.size() && st.top() >= printable.top()) {
//		cout << "printable.size : " << printable.size() << "\n";
		printable.pop();
	}
//	cout << "1\n";
	if (printable.size() == 0) print_num = -1;
	else print_num = printable.top();
	printable.push(st.top());
	st.pop();
	ft_recur(st, printable);
	cout << print_num << " ";
	return ;
}

int			main(void)
{
	int		N, A;
	stack<int>	st, printable;

	cin >> N;
	while (N--) {
		cin >> A;
		st.push(A);
	}
	printable.push(st.top());
	st.pop();
	ft_recur(st, printable);
	cout << "-1";
	return (0);
}
