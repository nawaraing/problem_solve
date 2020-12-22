#include <iostream>
#include <vector>
#include <limits.h>
#include <cmath>

using namespace std;

int		n, m, a, f;
int		safe;
int		pos, speed;
float	x, y, g;
vector<pair<int, int> >		car;		// < pos, speed >
float	minn = MAXFLOAT;
float	tmp;

class		bae_g
{
	public:

	float	min_drop_aria(void)
	{
		float	sec = y / (g / 2);

		return (x - sec * a);
	}

	float	max_drop_aria(void)
	{
		float	sec = y / (g / 2);

		return (x + sec * a);
	}

	bool	position_in_drop_aria(float position)
	{
		if (min_drop_aria() < position && position < max_drop_aria())
			return (true);
		return (false);
	}

	float	calcul_directly_position(float position)
	{
		float	dist = fabs(position - safe);
		float	sec = dist / a;
		float	drop = sec * g / 2;
		float	rest_sec = (y - drop) / g;

		return (sec + rest_sec);
	}

	float	take_car(pair<int, int> volvo)
	{
		if (position_in_drop_aria(volvo.first))
			calcul_directly_position(volvo.position);
		for (int i = 0; i < car.size(); i++)
		{
			if (car[i].pos)
		}
	}
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	class bae_g		bg;
	cin >> n >> m >> g >> a >> f >> y >> x >> safe;
	for (int i = 0; i < m; i++)
	{
		cin >> pos >> speed;
		car.push_back(make_pair(pos, speed));
	}
	if (bg.position_in_drop_aria(safe) && bg.calcul_directly_position(safe) < minn)
		minn = bg.calcul_directly_position(safe);
	//	아예 걸어가는 경우
	for (int i = 0; i < car.size(); i++);
	{
		if ((tmp = bg.take_car(car[i])) < minn)
			minn = tmp;
	}
	cout >> tmp;
	return (0);
}