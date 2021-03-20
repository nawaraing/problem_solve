#include <iostream>
#include <string>

using namespace std;

string		game;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (1)
	{
		cin >> game;
		if (game == "end")
			break ;
		int		xcnt = 0, ocnt = 0;
		for (int i = 0; i < 9; i++)
		{
			if (game[i] == 'X')
				xcnt++;
			else
				ocnt++;
		}
		if (xcnt != ocnt && xcnt != ocnt + 1)
		{
			cout << "invalid\n";
			continue ;
		}
		for (int i = 0; i < 3; i++)
		{
			if (game[i + 0] == game[i + 1] && game[i + 1] == game[i + 2])
		}
	}

	return (0);
}