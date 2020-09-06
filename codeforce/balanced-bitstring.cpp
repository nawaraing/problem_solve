#include <iostream>
#include <string>

#include <stdio.h>		//

using namespace std;

void		ft_fill_one_zero(string *str, int head, int tail, char num)
{
	string		s;

	s = *str;
	for (int i = head; i <= tail; i++) {
		if (s[i] == '?')
			s[i] = num;
	}
	*str = s;
	return ;
}

int		ft_cnt_zero_one(string *str, int head, int tale, int k, int *z, int *o)
{
	int		zero, one;
	string		s;

	s = *str;
	zero = 0; one = 0;
	for (int i = head; i <= tale; i++) {
		if (s[i] == '1') one++;
		else if (s[i] == '0') zero++;
	}
	if (one > k / 2 || zero > k / 2)
		return 0;
	else if (one == k / 2)
		ft_fill_one_zero(str, head, tale, '0');
	else if (zero == k / 2)
		ft_fill_one_zero(str, head, tale, '1');
	*z = k / 2 - zero;
	*o = k / 2 - one;
	return 1;
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int		t, k, n, tale, zero, one, keep;
	string		s;

	cin >> t;
	while (t--) {
		cin >> n; cin >> k;
		cin >> s;
		if (!ft_cnt_zero_one(&s, 0, k - 1, k, &zero, &one)) {
			cout << "NO";
			if (t != 0) cout << "\n";
			continue ;
		}
		keep = tale;
		for (int head = 0; head <= n - k - 1; head++) {
			tale = head + k - 1;
			if (s[head] == '?' && s[tale + 1] != '?') {
				if (head <= keep) {
					if (s[tale + 1] == '1')
						one--;
					else zero--;
				}
				if (zero < 0 || one < 0) {
					cout << "NO";
					if (t != 0) cout << "\n";
					break ;
				}
				continue ;
			}
			else if (s[head] != '?' && s[tale + 1] == '?') {
				s[tale + 1] = s[head];
				continue ;
			}
			else if (s[head] == '?' && s[tale + 1] == '?') {
				if (!ft_cnt_zero_one(&s, 0, k - 1, k, &zero, &one)) {
					cout << "NO";
					if (t != 0) cout << "\n";
					break ;
				}
				keep = tale;
			}
			if (s[head] != s[tale + 1]) {
				cout << "NO";
				if (t != 0) cout << "\n";
				break ;
			}
		}
		if (tale == n - 2) {
			cout << "YES";
			if (t != 0) cout << "\n";
		}	
	}
	return (0);
}
