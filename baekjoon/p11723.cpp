#include <iostream>
#include <cmath>
#include <cstring>

#define FULL 1048575

using namespace std;

class sets {
	public:
	
	int		ft_element(int deci) {
		int			ret = 1;

		return (ret << (deci - 1));
	}

	int		ft_add(int set, int element) {
		element = ft_element(element);
		return (set |= element);
	}

	int		ft_remove(int set, int element) {
		element = ft_element(element);
		return (set &= (FULL - element));
	}

	int		ft_check(int set, int element) {
		element = ft_element(element);
		set &= element;
		if (set == 0) cout << 0;
		else cout << 1;
		return (0);
	}

	int		ft_toggle(int set, int element) {
		element = ft_element(element);
		return (set ^= element);
	}

	int		ft_all(void) {
		return (FULL);
	}

	int		ft_empty(void) {
		return (0);
	}
};

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		m, element, sset = 0;
	string	str;
	sets	s;

	cin >> m;
	while (m--) {
		cin >> str;
		if (str[0] == 'a' && str[1] == 'd') {
			cin >> element;
			sset = s.ft_add(sset, element);
		}
		else if (str[0] == 'r') {
			cin >> element;
			sset = s.ft_remove(sset, element);
		}
		else if (str[0] == 'c') {
			cin >> element;
			s.ft_check(sset, element);
			if (m) cout << "\n";
		}
		else if (str[0] == 't') {
			cin >> element;
			sset = s.ft_toggle(sset, element);
		}
		else if (str[0] == 'a' && str[1] == 'l') sset = s.ft_all();
		else if (str[0] == 'e') sset = s.ft_empty();
		else cout << "wrong\n";
	}
	return (0);
}