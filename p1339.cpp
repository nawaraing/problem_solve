#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;				//		반례 : AAA BAA

int								alpha[26], cnt, sum, num, n;
string							str[10];
vector<pair<int, list<char> > >	v;									//	<digit, lst>
pair<int, list<char> >			tmp;
list<char>						lst;

bool	ft_sort(pair<int, list<char> > a, pair<int, list<char> > b) {return a.first < b.first;}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
		lst.clear();
		for (int j = 0; j < str[i].size(); j++)
			lst.push_back(str[i][j]);
		v.push_back(make_pair(str[i].size(), lst));
	}
	num = 9;
	while (v.size()) {
		sort(v.begin(), v.end(), ft_sort);
		tmp = v.back();
		v.pop_back();
		if (!alpha[tmp.second.front() - 'A']) alpha[tmp.second.front() - 'A'] = num--;
		if (!num) break ;
		if (tmp.second.size()){
			tmp.second.pop_front();
			v.push_back(make_pair(tmp.first - 1, tmp.second));
		}
	}
//	for (int i = 0; i < 26; i++) cout << alpha[i] << " ";
//	cout << "\n";
	for (int i = 0; i < n; i++) {
		num = 0;
		for (int j = 0; j < str[i].size(); j++)
			num = 10 * num + alpha[str[i][j] - 'A'];
		sum += num;
	}
	cout << sum;
	return (0);
}