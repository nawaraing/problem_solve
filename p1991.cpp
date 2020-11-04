#include <iostream>

using namespace std;

int			n;

void	ft_pre(char tree[26][3], int idx) {
	cout << tree[idx][0];
	if (tree[idx][1]) {
		for (int i = 0; i < n; i++) {
			if (tree[i][0] == tree[idx][1]) {
				ft_pre(tree, i);
				break ;
			}
		}
	}
	if (tree[idx][2]) {
		for (int i = 0; i < n; i++) {
			if (tree[i][0] == tree[idx][2]) {
				ft_pre(tree, i);
				break ;
			}
		}
	}
	return ;
}

void	ft_in(char tree[26][3], int idx) {
	if (tree[idx][1]) {
		for (int i = 0; i < n; i++) {
			if (tree[i][0] == tree[idx][1]) {
				ft_in(tree, i);
				break ;
			}
		}
	}
	cout << tree[idx][0];
	if (tree[idx][2]) {
		for (int i = 0; i < n; i++) {
			if (tree[i][0] == tree[idx][2]) {
				ft_in(tree, i);
			break ;
			}
		}
	}
	return ;
}

void	ft_post(char tree[26][3], int idx) {
	if (tree[idx][1]) {
		for (int i = 0; i < n; i++) {
			if (tree[i][0] == tree[idx][1]) {
				ft_post(tree, i);
				break ;
			}
		}
	}
	if (tree[idx][2]) {
		for (int i = 0; i < n; i++) {
			if (tree[i][0] == tree[idx][2]) {
				ft_post(tree, i);
				break ;
			}
		}
	}
	cout << tree[idx][0];
	return ;
}


int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	char			tree[26][3];
	char			c;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> c;
			if (c == '.') tree[i][j] = 0;
			else tree[i][j] = c;
		}
	}
	ft_pre(tree, 0);
	cout << "\n";
	ft_in(tree, 0);
	cout << "\n";
	ft_post(tree, 0);
	return (0);
}
