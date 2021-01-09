#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <functional>

using namespace std;

map<string, pair<vector<string>, vector<string> > >	mapping;	// 앨범명 : < 부모 + 하위 앨범, 하위 사진 >
string			cur, oldcur, home = "album", cmd, param;
vector<string>	albs, pics;
int			n;

class		c_works
{
	public:
	void	mkalb(string param)
	{
		int		flag = 0;
		for (int i = 1; i < mapping[cur].first.size(); i++)
		{
			if (mapping[cur].first[i] == param)
			{
				cout << "duplicated album name\n";
				flag = 1;
				break ;
			}
		}
		if (flag == 0)
		{
			mapping[cur].first.push_back(param);
			albs.clear();
			pics.clear();
			albs.push_back(cur);
			mapping[param] = make_pair(albs, pics);
		}
		cout << "\nalbum : ";
		for (int i = 1; i < mapping[cur].first.size(); i++)
		{
			cout << mapping[cur].first[i] << " ";
		}
		cout << "\n";	//
	}

	pair<long long, long long>	delete_alb(string target)
	{
		// cout << "delet " << target << "\n";
		pair<long long, long long>		ret, tmp;
		string				parent = mapping[target].first[0];
		for (int i = 1; i < mapping[parent].first.size(); i++)
		{
			if (mapping[parent].first[i] == target)
			{
				mapping[parent].first.erase(mapping[parent].first.begin() + i);
				break ;
			}
		}
		// for (int i = 1; i < mapping[parent].first.size(); i++)
		// {
		// 	cout << mapping[parent].first[i] << " ";
		// }
		// cout << "\n";	//
		ret.first = 1; // mapping[target].first.size();
		ret.second = mapping[target].second.size();
		for (int i = 1; i < mapping[target].first.size(); i++)
		{
			string	child = mapping[target].first[i];
			tmp = delete_alb(child);
			ret.first += tmp.first;
			ret.second += tmp.second;
		}
		// albs.clear();
		// pics.clear();
		// mapping[target] = make_pair(albs, pics);
		return (ret);
	}

	void	rmalb(string param)
	{
		string		target;
		int			flag = 0;
		if (param == "-1")
		{
			if (mapping[cur].first.size() > 1)
			{
				sort(mapping[cur].first.begin() + 1, mapping[cur].first.end(), greater<string>());
				target = mapping[cur].first.back();
				mapping[cur].first.pop_back();
				flag = 1;
			}
		}
		else if (param == "0")
		{
			for (int i = 1; i < mapping[param].first.size(); i++)
			{
				delete_alb(mapping[param].first[i]);
			}
			flag = 1;
		}
		else if (param == "1")
		{
			if (mapping[cur].first.size() > 1)
			{
				sort(mapping[cur].first.begin() + 1, mapping[cur].first.end());
				target = mapping[cur].first.back();
				mapping[cur].first.pop_back();
				flag = 1;
			}
		}
		else
		{
			for (int i = 1; i < mapping[cur].first.size(); i++)
			{
				if (mapping[cur].first[i] == param)
				{
					target = param;
					flag = 1;
					break ;
				}
			}
		}
		pair<long long, long long>		pr, tmp;
		if (flag == 1)
		{
			if (param == "0")
			{
				pr.first = 0; pr.second = 0;
				int		size = mapping[cur].first.size();
				for (int i = 1; i < size; i++)
				{
					tmp = delete_alb(mapping[cur].first[1]);
					pr.first += tmp.first;
					pr.second += tmp.second;
				}
			}
			else pr = delete_alb(target);
		}
		cout << pr.first << " " << pr.second << "\n";
	}

	void	insert(string param)
	{
		int		flag = 0;
		for (int i = 0; i < mapping[cur].second.size(); i++)
		{
			if (mapping[cur].second[i] == param)
			{
				cout << "duplicated photo name\n";
				flag = 1;
				break ;
			}
		}
		if (flag == 0)
			mapping[cur].second.push_back(param);
		cout << "\ninsert : ";
		for (int i = 0; i < mapping[cur].second.size(); i++)
		{
			cout << mapping[cur].second[i] << " ";
		}
		cout << "\n";	//

	}

	void	deletes(string param)
	{
		string		target;
		long long	ret = 0;
		if (param == "-1")
		{
			if (mapping[cur].second.size() > 0)
			{
				sort(mapping[cur].second.begin(), mapping[cur].second.end(), greater<string>());
				mapping[cur].second.pop_back();
				ret++;
			}
		}
		else if (param == "0")
		{
			long long size = mapping[cur].second.size();
			for (int i = 0; i < size; i++)
			{
				mapping[cur].second.erase(mapping[cur].second.begin());
				ret++;
			}
		}
		else if (param == "1")
		{
			if (mapping[cur].second.size() > 0)
			{
				sort(mapping[cur].second.begin(), mapping[cur].second.end());
				mapping[cur].second.pop_back();
				ret++;
			}
		}
		else
		{
			for (int i = 0; i < mapping[cur].second.size(); i++)
			{
				if (mapping[cur].second[i] == param)
				{
					mapping[cur].second.erase(mapping[cur].second.begin() + i);
					ret++;
					break ;
				}
			}
		}
		// for (int i = 0; i < mapping[cur].second.size(); i++)
		// {
		// 	cout << mapping[cur].second[i] << " ";
		// }
		// cout << "\n";	//

		cout << ret <<  "\n";
	}

	void	ca(string param)
	{
		if (param == "..")
		{
			oldcur = cur;
			cur = mapping[cur].first[0];
		}
		else if (param == "/")
		{
			oldcur = cur;
			cur = home;
		}
		else {
			for (int i = 1; i < mapping[cur].first.size(); i++)
			{
				if (mapping[cur].first[i] == param)
				{
					oldcur = cur;
					cur = param;
				}
			}
		}
		cout << cur << "\n";
	}
};

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	c_works		works;
	albs.push_back(home);
	mapping[home] = make_pair(albs, pics);
	cur = home;
	oldcur = home;
	cin >> n;
	while (n--)
	{
		cin >> cmd >> param;
		if (cmd == "mkalb")
			works.mkalb(param);
		else if (cmd == "rmalb")
			works.rmalb(param);
		else if (cmd == "insert")
			works.insert(param);
		else if (cmd == "delete")
			works.deletes(param);
		else if (cmd == "ca")
			works.ca(param);
		// else
		// 	cout << "check line 43\n";
	}
	return (0);
}