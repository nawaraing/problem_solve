#include <iostream>
#include <cstring>

using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int		n, m;
	string	postit, candidate;

	cin >> n>> m;
	cin >> postit;
	while (m--)
	{
		cin >> candidate;
		int		idx = 0;
		for (int i =0 ; i < candidate.size(); i++)
		{
			if (!postit[idx]) break ;
			if (postit[idx] == candidate[i])
				idx++;
		}
		if (postit[idx]) cout << "false";
		else cout << "true";
		if (m) cout << "\n";
	}
	return (0);
}