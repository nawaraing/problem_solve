#include <iostream>
#include <stack>

using namespace std;

double 		n, l;
stack<int>	st;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> l;
	while (n--)
	{
		double 		x;
		cin >> x;
		st.push(x);
	}
	double		mid = 0;
	double		cnt = 0;
	int		flag = 0;
	double		sum = 0;
	while (!st.empty())
	{
		double		 a = st.top();
		st.pop();
		cnt++;
		sum += a;
		// mid *= (cnt - 1) / cnt;
		// a /= cnt;
		mid = sum / cnt;
		// cout << mid << " ";
		if (st.size() && (mid <= st.top() - l || st.top() + l <= mid))
		{
			flag = 1;
			break ;
		}
	}
	if (flag) cout << "unstable";
	else cout << "stable";
	return (0);
}