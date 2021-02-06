#include <iostream>
#include <cstring>

using namespace std;

struct	Trie {
	bool	finish = false;
	Trie	*next[26];
	Trie() {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (next[i]) delete next[i];
	}

	void	insert(const char *key)
	{
		if (*key == '\0')
			finish = true;
		else
		{
			int		curr = *key - 'a';
			if (next[curr] == NULL)
				next[curr] = new Trie();
			next[curr]->insert(key + 1);
		}
	}

	int		find(const char *key)
	{
		if (*key == '\0')
		{
			if (finish) return (1);
			else return (0);
		}
		int		curr = *key - 'a';
		if (next[curr] == NULL) return (0);
		return (next[curr]->find(key + 1));
	}
};

int		n, m, ret;
char	s[10000];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	Trie	*head = new Trie();
	while (n--)
	{
		cin >> s;
		head->insert(s);
	}
	while (m--)
	{
		cin >> s;
		if (head->find(s)) ret++;
	}
	cout << ret;
	return (0);
}