#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int					t, n, m, a, b;
int					parent[100000], rece[100000], scc_arr[100000];
bool				used[100000];
stack<int>			st;
vector<int>			graph[100000], v;
vector<vector<int> >	scc;

void	ft_dfs(int idx) {
	int			next, tmp;

	cout << "idx : " << idx << "\n";						///////////////
	for (int i = 0; i < graph[idx].size(); i++) {
		next = graph[idx][i];
		if (used[next]) continue ;
		st.push(next);
		parent[next] = tmp = idx;
		while (tmp != next) {					// parent search
			tmp = parent[tmp];
			if (tmp == -1 || scc.size() > tmp) {
				tmp = -1;
				break ;
			}
		}
		/////
		if (tmp != -1) {						// if scc
			v.clear();
			v.push_back(st.top());
			st.pop();
			used[next] = 1;
			a = scc.size();
			scc_arr[next] = a;
			while (st.top() != next) {
				v.push_back(st.top());
				used[st.top()] = 1;
				scc_arr[st.top()] = a;
				st.pop();
			}
			st.pop();
			scc.push_back(v);
		}
		else ft_dfs(next);
	}
}

void	ft_scc(void) {
	for (int i = 0; i < n; i++) {
		parent[i] = -1;
		scc_arr[i] = -1;
		used[i] = 0;
	}
	while (st.size()) st.pop();
	for (int i = 0; i < n; i++) {
		if (used[i]) continue ;
		while (st.size()) st.pop();
		st.push(i);
		ft_dfs(i);
		while(st.size()) {
			v.clear();
			v.push_back(st.top());
			used[st.top()] = 1;
			scc_arr[st.top()] = scc.size();
			scc.push_back(v);
			st.pop();
		}
	}
}

int		ft_find_head(void)
{
	for (int i = 0; i < scc.size(); i++) {
		for (int j = 0; j < scc[i].size(); j++) {
			a = scc[i][j];
			for (int k = 0; k < graph[a].size(); k++) {
				b = graph[a][k];
				if (scc_arr[a] == scc_arr[b]) continue ;
				rece[scc_arr[b]]++;
			}
		}
	}
	int		ret = -1;
	for (int i = 0; i < scc.size(); i++) {
		if (!rece[i]) {
			if (ret == -1) ret = i;
			else return (-1);
		}
	}
	return (ret);
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			rece[i] = 0;
			graph[i].clear();
		}
		scc.clear();
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			graph[a].push_back(b);
		}
		ft_scc();
/*
		cout << "\nscc\n\n";
		for (int i = 0; i < scc.size(); i++) {
			for (int j = 0; j < scc[i].size(); j++) {
				cout << scc[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\nscc_arr\n\n";
		for (int i = 0; i < n; i++) cout << scc_arr[i] << " ";
		cout << "\n";
*/
		for (int i = 0; i < scc.size(); i++) rece[i] = 0;
		int		ret = ft_find_head();
		if (ret == -1) cout << "Confused";
		else {
			sort(scc[ret].begin(), scc[ret].end());
			for (int i = 0; i < scc[ret].size(); i++) {
				cout << scc[ret][i];
				if (i != scc[ret].size() - 1) cout << "\n";
			}
		}
		if (t) {
			cout << "\n\n";
		}
	}
	return (0);
}