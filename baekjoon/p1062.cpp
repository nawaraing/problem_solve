#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int				n, k, whole, use, word, maxi, ret, done;
string			str;
vector<string>	v;

class	c_word {
	public:

	int			ctoi(int c) {
		return (1 << (c - 'a'));
	}

	int			add(int dest, int c) {
		return (dest | ctoi(c));
	}

	int			stoi(string str) {
		int			ret = 0;

		for (int i = 4; i < str.size() - 4; i++) ret |= ctoi(str[i]);
		return (ret);
	}

	int			isvalid(string str) {
		if ((use & stoi(str)) == stoi(str)) return (1);
		return (0);
	}
};

void	ft_backtracking(int cnt, int idx) {
	c_word		w;

	if (cnt == done) {
		ret = 0;
		for (int i = 0; i < n; i++) {
			if (w.isvalid(v[i])) ret++;
		}
		if (ret > maxi) maxi = ret;
	}
	if (maxi == n) return ;

	for (int i = idx; i < 26; i++) {
		if ((whole | (1 << i)) && !(use & (1 << i))) {
			use |= (1 << i);
			ft_backtracking(cnt + 1, i + 1);
			use &= ~(1 << i);
		}
	}
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	c_word		w;
	cin >> n >> k;
	whole = w.add(whole, (int)'a');
	whole = w.add(whole, (int)'n');
	whole = w.add(whole, (int)'t');
	whole = w.add(whole, (int)'i');
	whole = w.add(whole, (int)'c');
	use = whole;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 4; j < str.size() - 4; j++) whole = w.add(whole, str[j]);
		v.push_back(str);
	}
	if (k < 5) {
		cout << 0;
		return (0);
	}
	done = k - 5;
	ft_backtracking(0, 0);
	cout << maxi;
	return (0);
}