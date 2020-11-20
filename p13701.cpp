#include <iostream>
#include <vector>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int>			v;
	int					num;
	bool				flag;
	
	while (scanf("%d", &num) == 1) {
		flag = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == num) {
				flag = 1;
				break ;
			}
		}
		if (!flag) {
			if (!v.empty()) cout << " ";
			cout << num;
			v.push_back(num);
		}
	}
	return (0);
}