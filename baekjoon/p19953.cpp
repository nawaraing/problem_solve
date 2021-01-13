#include <iostream>
#include <vector>

using namespace std;

vector<int>		vec;
int		v, m, t, x = 0, y = 0, divi, mod;

void	north(void)
{
	int							cnt;
	vector<int>					val;

	cnt = divi - 1;
	if (mod > 0) cnt++;
	int		idx = 3 % vec.size();
	val.push_back(vec[idx]);
	// cout << "val : ";
	// for (int i =0; i < val.size(); i++) cout << val[i] << " ";
	// cout << "\n";
	while (val[0] != vec[(idx + 4) % (int)vec.size()])
		val.push_back(vec[(idx + 4) % (int)vec.size()]);

	int		ddiv = cnt / val.size();
	int		mmod = cnt % val.size();
	int		extra = 0;
	for (int i =0; i < val.size(); i++)
	{
		if (mmod > 0) extra = 1;
		else extra = 0;
		y += val[i] * (ddiv + extra);
		// cout << "y : " << y << "\n";
		if (mmod > 0) mmod--;
	}
}

void	south(void)
{
	int							cnt;
	vector<int>					val;

	cnt = divi;
	if (mod > 2) cnt++;
	int		idx = 1 % vec.size();
	val.push_back(vec[idx]);
	// cout << "val : ";
	// for (int i =0; i < val.size(); i++) cout << val[i] << " ";
	// cout << "\n";
	while (val[0] != vec[(idx + 4) % (int)vec.size()])
		val.push_back(vec[(idx + 4) % (int)vec.size()]);

	int		ddiv = cnt / val.size();
	int		mmod = cnt % val.size();
	int		extra = 0;
	for (int i =0; i < val.size(); i++)
	{
		if (mmod > 0) extra = 1;
		else extra = 0;
		y -= val[i] * (ddiv + extra);
		// cout << "y : " << y << "\n";
		if (mmod > 0) mmod--;
	}
}

void	east(void)
{
	int							cnt;
	vector<int>					val;

	cnt = divi;
	if (mod > 1) cnt++;
	int		idx = 0;
	val.push_back(vec[idx]);
	// cout << "val : ";
	// for (int i =0; i < val.size(); i++) cout << val[i] << " ";
	// cout << "\n";
	while (val[0] != vec[(idx + 4) % (int)vec.size()])
		val.push_back(vec[(idx + 4) % (int)vec.size()]);

	int		ddiv = cnt / val.size();
	int		mmod = cnt % val.size();
	int		extra = 0;
	for (int i =0; i < val.size(); i++)
	{
		if (mmod > 0) extra = 1;
		else extra = 0;
		x += val[i] * (ddiv + extra);
		// cout << "x : " << x << "\n";
		if (mmod > 0) mmod--;
	}
}

void	west(void)
{
	int							cnt;
	vector<int>					val;

	cnt = divi;
	int		idx = 2 % vec.size();
	val.push_back(vec[idx]);
	// cout << "val : ";
	// for (int i =0; i < val.size(); i++) cout << val[i] << " ";
	// cout << "\n";
	while (val[0] != vec[(idx + 4) % (int)vec.size()])
		val.push_back(vec[(idx + 4) % (int)vec.size()]);

	int		ddiv = cnt / val.size();
	int		mmod = cnt % val.size();
	int		extra = 0;
	for (int i =0; i < val.size(); i++)
	{
		if (mmod > 0) extra = 1;
		else extra = 0;
		x -= val[i] * (ddiv + extra);
		// cout << "x : " << x << "\n";
		if (mmod > 0) mmod--;
	}
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> v >> m >> t;
	y += v;
	vec.clear();
	v = (v * m) % 10;
	vec.push_back(v);
	while (vec[0] != ((v * m) % 10))
	{
		v = (v * m) % 10;
		vec.push_back(v);
	}
	// cout << "vec : ";
	// for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
	// cout << "\n";
	divi = t / 4;
	mod = t % 4;
	north();
	south();
	east();
	west();
	cout << x << " " << y;
	return (0);
}