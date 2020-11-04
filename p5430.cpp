#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
#include <string>
#include <list>
//#include <algorithm>

using namespace std;

int		ft_atoi(string s)
{
	int		ans = 0;
	for (unsigned int i = 0; i < s.length(); i++) {
		ans = ans * 10 + s[i] - '0';
	}
	return ans;
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	bool		vec, flag;
	int			t, n;
	string		p, nums, digit;
	list<int>	l;

	cin >> t;
	while (t--) {
		flag = 0; vec = 0;
		cin >> p; cin >> n; cin >> nums;
//		cout << "\nnums : " << nums << "\n";
		for (unsigned int i = 1; i < nums.length() - 1; i++) {
			digit.clear();
			while (nums[i] != ',' && nums[i] != ']')  {
			//	cout << nums[i];
				digit.insert(digit.end(), 1, nums[i++]);
			}
			l.push_back(ft_atoi(digit));
//			cout << l.back() << "\n";
		}
		for (unsigned int i = 0; i < p.length(); i++) {
			if (p[i] == 'R')
				vec = !vec;
			else {
				if (!l.size()) {flag = 1; break;}
				else if (vec)
					l.pop_back();
				else
					l.pop_front();
			}
//			cout << "vec : " << vec << "\n";
		}
		if (flag == 1) cout << "error";
		else {
			cout << "[";
			while (l.size()) {
				if (vec) {
					cout << l.back();
					l.pop_back();
				if (l.size()) cout << ",";
				}
				else {
					cout << l.front();
					l.pop_front();
					if (l.size()) cout << ",";
				}
			}
			cout << "]";
		}
		if (t != 0) cout << "\n";
	}
	return (0);
}
