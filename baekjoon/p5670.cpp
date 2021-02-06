#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

struct	Trie
{
	Trie	*next[26];
	int		finish;
	int		words;
	int		bridge;
	Trie() {
		finish = 0;
		words = 0;
		bridge = 0;
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (next[i]) delete next[i];
	}

	void	insert(const char *key)
	{
		words++;
		if (*key == '\0')
			finish = 1;
		else {
			int		curr = *key - 'a';
			if (next[curr] == NULL)
			{
				bridge++;
				next[curr] = new Trie();
			}
			next[curr]->insert(key + 1);
		}
	}

	int		count(void)
	{
		int		ret = 0;
		if (bridge == 0)
			return (0);
		else if (bridge == 1)
		{
			for (int i = 0; i < 26; i++)
			{
				if (next[i])
					ret += next[i]->count();
			}
			if (finish) ret += words - 1;
		}
		else
		{
			for (int i = 0; i < 26; i++)
			{
				if (next[i])
					ret += next[i]->count();
			}
			ret += words;
			ret -= finish;
		}
		return (ret);
	}
};

int		n;
char	str[81];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> n)
	{
		Trie	*head = new Trie();
		for (int i = 0; i < n; i++)
		{
			cin >> str;
			head->insert(str);
		}
		double		ret = (double)n;
		for (int i = 0; i < 26; i++)
		{
			if (head->next[i])
			{
				ret += (double)head->next[i]->count();
			}
		}
		printf("%.2lf\n", ret / (double)n);
		delete head;
	}
	return (0);
}