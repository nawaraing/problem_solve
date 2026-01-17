#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			n, a, b;
	int			num, cnt = 0;
	vector<int>	v, ans;
    static int         left[500001], right[500001];
	v.clear();
	v.push_back(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
        left[a] = b;
        right[b] = a;
    }
    for (int i = 0; i <= 500000; i++)
    {
        num = left[i];
        if (num == 0) continue;

		if (v.back() < num)
		{
			v.push_back(num);
		}
		else {
            // std::cout << "num: " << num << "\n";
			vector<int>::iterator itr = lower_bound(v.begin(), v.end(), num);			
            ans.push_back(right[*itr]);
            *itr = num;
			cnt++;
        }
	}
	std::cout << cnt << "\n";
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << "\n";
    }
	return (0);
}