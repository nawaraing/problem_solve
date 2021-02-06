#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int		dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int		dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int		num = 0;
int		visit[4][4];
int		n, m, board[4][4], cnt = 0, maxlen = 0;
vector<int>		v;


struct	Trie {
	Trie	*next[26];
	int		finish;
	Trie() {
		finish = 0;
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (next[i]) delete next[i];
	}

	void	insert(const char *key)
	{
		if (*key == '\0')
			finish = num;		// 각 단어의 고유넘버
		else
		{
			int		curr = *key - 'a';
			if (next[curr] == NULL)
				next[curr] = new Trie();
			next[curr]->insert(key + 1);
		}
	}

	int		find(int r, int c)
	{
		int		curr = board[r][c] - 'a';
		if (next[curr] == NULL) return (0);
		if (finish > 0)
			v.push_back(finish);
		for (int i = 0; i < 8; i++)
		{
			int		nextr = r + dr[i];
			int		nextc = c + dc[i];
			return (next[curr]->find(nextr, nextc));
		}
		return (0);
	}
};

int		scoreof(int	len)
{
	if (len < 3) return (0);
	if (len == 3 || len == 4) return (1);
	if (len == 5) return (2);
	if (len == 7) return (5);
	if (len == 8) return (11);
	return (-1);
}

char	s[9];
char	words[31][9];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	Trie	*head = new Trie();
	while (n--)
	{
		cin >> s;
		strcpy(words[++num], s);
		head->insert(s);
		cout << "s :" << s << "\n";
	}
	cin >> m;
	while (m--)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				char c;
				cin >> c;
				board[i][j] = c;
				visit[i][j] = 0;
			}
		}
		v.clear();
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				head->find(i, j);
			}
		}
		cout << "v.size : " << v.size() << "\n";
		for (int i = 0; i < v.size(); i++)
		{
			int		tmp = v[i];
			if (strlen(words[tmp]) == strlen(words[maxlen]))
			{
				if (strcmp(words[tmp], words[maxlen]) < 0)
					maxlen = tmp;
			}
			else if (strlen(words[tmp]) > strlen(words[maxlen]))
				maxlen = tmp;
		}
		printf("%d %s %lu\n", scoreof(strlen(words[maxlen])), words[maxlen], v.size());
	}
	return (0);
}