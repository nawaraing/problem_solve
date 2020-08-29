#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

int		ft_isfly(vector<pair<int, int> > v, int i, int j)
{
	for (int k = 0; k < v.size(); k++)
		if ((v[k]).first == i && (v[k]).second == j) return 1;
	return 0;
}

void		print_box(pair<int, int> racket, vector<pair<int, int> > v, int R, int S, int K)
{
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < S; j++) {
			if (i == racket.first - 1 && j == racket.second - 1) cout << "+";
			else if (i == racket.first - 1 && j == racket.second + K - 2) cout << "+";
			else if (i == racket.first + K - 2 && j == racket.second - 1) cout << "+";
			else if (i == racket.first + K - 2 && j == racket.second + K - 2) cout << "+";
			else if (i == racket.first - 1 && j > racket.second - 1 && j < racket.second + K - 2) cout << "-";
			else if (i == racket.first + K - 2 && j > racket.second - 1 && j < racket.second + K - 2) cout << "-";
			else if (i > racket.first - 1 && i < racket.first + K - 2 && j == racket.second - 1) cout << "|";
			else if (i > racket.first - 1 && i < racket.first + K - 2 && j == racket.second + K - 2) cout << "|";
			else if (ft_isfly(v, i, j)) cout << "*";
			else cout << ".";
		}
		cout << "\n";
	}
	return ;
}

int		main(void)
{
	int				R, S, K, nums, max = 0;
	string				str;
	vector<pair<int, int> >		v;
	pair<int, int>			racket;

	cin >> R; cin >> S; cin >> K;
	for (int i = 0; i < R; i++) {
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '*') v.push_back(make_pair(i, j));
		}
	}
	for (int i = 0; i <= R - K + 1; i++) {
		for (int j = 0; j <= S - K + 1; j++) {
			nums = 0;
			for (int l = 0; l < v.size(); l++) {
				if ((v[l]).first < i) continue ;
				else if ((v[l]).first >= (i + K - 2)) break ;
				if ((v[l]).second >= j && (v[l]).second < (j + K - 2))
					nums++;
			}
			if (nums > max) {
				max = nums;
				racket = make_pair(i, j);
			}
		}
	}
	cout << max << "\n";
	print_box(racket, v, R, S, K);
	return (0);
}
