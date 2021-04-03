#include <iostream>
#include <vector>
#include <string>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		t, n;
	string	s;

	cin >> t;
	while (t--)
	{
		cin >> n >> s;
		int			acnt = 1;
		int			bcnt = 1;
		vector<int>		a, b;

		if (s[0] != '1' || s[n - 1] != '1')		// 양 끝이 같아야함
		{
			cout << "NO";
			if (t) cout << endl;
			continue ;
		}
		int		zero_cnt = 0;
		for (int i = 1; i < n - 1; i++)
		{
			if (s[i] == '0')
			{
				zero_cnt++;
				if (acnt == 0 && bcnt == 0)
				{
					cout << "error" << endl;
				}
				else if (acnt > bcnt)
				{
					a.push_back(1);
					b.push_back(0);
					acnt--;
					bcnt++;
				}
				else
				{
					a.push_back(0);
					b.push_back(1);
					acnt++;
					bcnt--;
				}
			}
			else
			{
				if (acnt > 0 && bcnt > 0)
				{
					if (acnt == 1 && bcnt == 1 && s[i + 1] == '0')
					{
						a.push_back(0);
						b.push_back(0);
						acnt++;
						bcnt++;
					}
					else
					{
						a.push_back(1);
						b.push_back(1);
						acnt--;
						bcnt--;
					}
				}
				else
				{
					a.push_back(0);
					b.push_back(0);
					acnt++;
					bcnt++;
				}
			}
		}
		if (zero_cnt % 2)
		{
			cout << "NO";
			if (t) cout << endl;
			continue ;
		}
		else
		{
			cout << "YES" << endl;
			cout << '(';
			for (int i = 0; i < n - 2; i++)
			{
				if (a[i] == 0)
					cout << '(';
				else
					cout << ')';
			}
			cout << ')' << endl;
			cout << '(';
			for (int i = 0; i < n - 2; i++)
			{
				if (b[i] == 0)
					cout << '(';
				else
					cout << ')';
			}
			cout << ')';
			if (t) cout << endl;
			continue ;
		}
	}
	return (0);
}
