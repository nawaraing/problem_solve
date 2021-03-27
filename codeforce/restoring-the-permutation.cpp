#include <iostream>
#include <deque>
#include <queue>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		used[200001];
	int		t, n, a;

	cin >> t;
	while (t--)
	{
		deque<int>		dqmin, dqmax;
		queue<int>		minn, maxi;
		int		before = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			// cout << "a: " << a << endl;
			if (before != a)
			{
				minn.push(a);
				maxi.push(a);
				for (int j = before + 1; j < a; j++)
				{
					dqmin.push_back(j);
					dqmax.push_back(j);
				}
				before = a;
			}
			else
			{
				minn.push(dqmin.front());
				maxi.push(dqmax.back());
				dqmin.pop_front();
				dqmax.pop_back();
			}
		}
		// cout << "min: ";
		while (!minn.empty())
		{
			cout << minn.front();
			minn.pop();
			if (!minn.empty()) cout << " ";
		}
		cout << endl;
		// cout << "max: ";
		while (!maxi.empty())
		{
			cout << maxi.front();
			maxi.pop();
			if (!maxi.empty()) cout << " ";
		}
		if (t) cout << endl;
	}
	return (0);
}
