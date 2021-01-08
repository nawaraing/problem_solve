#include <iostream>
#include <cmath>


using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int			br, bc, dr, dc, jr, jc;

	cin >> br >> bc >> dr >> dc >> jr >> jc;

	int			maxi = abs(br - jr);
	if (maxi < abs(bc - jc))
		maxi = abs(bc - jc);
	// cout << maxi << "\n";
	// cout << abs(dr - jr) + abs(dc - jc);
	if (maxi < abs(dr - jr) + abs(dc - jc))
		cout << "bessie";
	else if (maxi == abs(dr - jr) + abs(dc - jc))
		cout << "tie";
	else
	{
		cout << "daisy";
	}	
	return (0);
}