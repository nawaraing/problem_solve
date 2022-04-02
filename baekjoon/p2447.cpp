#include <iostream>

using namespace std;

bool	board[6561][6561];

void	star(int n, int x, int y) {
	int		sep = n/3;

	if (n == 1) { board[x][y] = true ; return ;}

	star(sep, x-sep, y-sep);
	star(sep, x, y-sep);
	star(sep, x+sep, y-sep);
	star(sep, x-sep, y);
	star(sep, x+sep, y);
	star(sep, x-sep, y+sep);
	star(sep, x, y+sep);
	star(sep, x+sep, y+sep);

}

int		main(void)
{
	int		n;

	cin >> n;
	star(n, n/2, n/2);

	for (int iX=0 ; iX<n ; iX++) {
		for (int iY=0 ; iY<n ; iY++) {
			if (board[iX][iY]) cout << "*";
			else cout << " ";
		}
		cout << "\n";
	}
}
