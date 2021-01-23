#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

map<int, pair<set<pair<string, int> >, set<string> > >		mapping;		// alb_num : < child albs, child pics >
vector<int, pair<string, int> >								parent;						// < name, alb_num >
int															alb_num;					// 0 is home
set<string>													pics;
set<pair<string, int> >										albs;
pair<string, int>											path;						// < name, num >


void	mkalb(string param)
{
	set<pair<string, int> >			child_albs = mapping[path.second].first;
	int								flag = 0;

	if (child_albs.find())
	{
		flag = 1;
		cout << "duplicated album name\n";
		break ;
	}
	}
	if (!flag)
	{
		mapping[path.second].first.push_back(make_pair(param, ++alb_num));
		albs.clear(); pics.clear();
		mapping[alb_num] = make_pair(albs, pics);
		parent.push_back(make_pair(path.first, path.second));
	}
}

pair<int, int>			remove_alb(int target_albnum)
{
	pair<int, int>	ret, tmp;

	// 부모 찾아가서 타겟 앨범을 지움, 타겟에 부모를 -1로 리셋
	parent[target_albnum].first = "";
	parent[target_albnum].second = -1;

	ret.first = 1;
	ret.second = mapping[target_albnum].second.size();
	int		size = mapping[target_albnum].first.size();
	for (int i = 0; i < size; i++)
	{
		int		target_num = mapping[target_albnum].first.back().second;
		mapping[target_albnum].first.pop_back();
		tmp = remove_alb(target_num);
		ret.first += tmp.first;
		ret.second += tmp.second;
	}
	return (ret);
}

void	rmalb(string param)
{
	pair<int, int>		ret, tmp;

	ret.first = 0;
	ret.second = 0;
	if (param == "-1")
	{
		if (mapping[path.second].first.size())
		{
			sort(mapping[path.second].first.begin(), mapping[path.second].first.end(), greater<pair<string, int> >());
			int		target_num = mapping[path.second].first.back().second;
			mapping[path.second].first.pop_back();
			ret = remove_alb(target_num);
		}
	}
	else if (param == "0")
	{
		int		size = mapping[path.second].first.size();
		// cout << "path : " << path.first << "\n";
		for (int i = 0; i < size; i++)
		{
			pair<int, int>		tmp;
			tmp = remove_alb(mapping[path.second].first.back().second);
			ret.first += tmp.first;
			ret.second += tmp.second;
			mapping[path.second].first.pop_back();
		}
	}
	else if (param == "1")
	{
		if (mapping[path.second].first.size())
		{
			sort(mapping[path.second].first.begin(), mapping[path.second].first.end());
			int		target_num = mapping[path.second].first.back().second;
			ret = remove_alb(mapping[path.second].first.back().second);
			mapping[path.second].first.pop_back();
		}
	}
	else
	{
		for (int i = 0; i < mapping[path.second].first.size(); i++)
		{
			if (param == mapping[path.second].first[i].first)
			{
				int		target_num = mapping[path.second].first[i].second;
				mapping[path.second].first.erase(mapping[path.second].first.begin() + i);
				ret = remove_alb(target_num);
				break ;
			}
		}
	}
	cout << ret.first << " " << ret.second << "\n";
}

void	insert(string param)
{
	vector<string>		child_pics = mapping[path.second].second;
	int					flag = 0;

	for (int i = 0; i < child_pics.size(); i++)
	{
		if (param == child_pics[i])
		{
			flag = 1;
			cout << "duplicated photo name\n";
			break ;
		}
	}
	if (!flag)
		mapping[path.second].second.push_back(param);
}

void	deletes(string param)
{
	int			ret = 0;
	if (param == "-1")
	{
		if (mapping[path.second].second.size())
		{
			sort(mapping[path.second].second.begin(), mapping[path.second].second.end(), greater<string>());
			mapping[path.second].second.pop_back();
			ret = 1;
		}
	}
	else if (param == "0")
	{
		ret = mapping[path.second].second.size();
		mapping[path.second].second.clear();
	}
	else if (param == "1")
	{
		if (mapping[path.second].second.size())
		{
			sort(mapping[path.second].second.begin(), mapping[path.second].second.end());
			mapping[path.second].second.pop_back();
			ret = 1;
		}
	}
	else
	{
		for (int i = 0; i < mapping[path.second].second.size(); i++)		//
		{
			if (param == mapping[path.second].second[i])
			{
				mapping[path.second].second.erase(mapping[path.second].second.begin() + i);
				ret = 1;
				break ;
			}
		}
	}
	cout << ret << "\n";
}

void	ca(string param)
{
	if (param == "..")
	{
		cout << parent[path.second].first << "\n";
		path.first = parent[path.second].first;
		path.second = parent[path.second].second;
	}
	else if (param == "/")
	{
		path = make_pair("album", 0);
		cout << "album\n";
	}
	else
	{
		int		flag = 0;

		for (int i = 0; i < mapping[path.second].first.size(); i++)
		{
			if (param == mapping[path.second].first[i].first)
			{
				flag = 1;
				path = make_pair(param, mapping[path.second].first[i].second);
				cout << param << "\n";
				break ;
			}
		}
		if (!flag)
			cout << path.first << "\n";
	}
	
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	mapping[alb_num] = make_pair(albs, pics);
	parent.push_back(make_pair("album", alb_num));
	path = make_pair("album", alb_num);
	int		n;
	cin >> n;
	while (n--)
	{
		string		cmd, param;
		cin >> cmd >> param;
		if (cmd == "mkalb")
			mkalb(param);
		else if (cmd == "rmalb")
			rmalb(param);
		else if (cmd == "insert")
			insert(param);
		else if (cmd == "delete")
			deletes(param);
		else if (cmd == "ca")
			ca(param);
		else cout << "cmd error\n";
	}
	return (0);
}