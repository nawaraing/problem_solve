#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

void	ft_Left(list<char>::iterator *cs_iter, list<char>::iterator begin_iter)
{
	if (*cs_iter != begin_iter) (*cs_iter)--;
	return ;
}

void	ft_D(list<char>::iterator *cs_iter, list<char>::iterator end_iter)
{
	if (*cs_iter != end_iter) (*cs_iter)++;
	return ;
}

void	ft_Backspace(list<char>::iterator cs_iter, list<char> *l)
{
	if (cs_iter == (*l).begin()) return ;
	cs_iter--;
	(*l).erase(cs_iter);
	return ;
}

int	main(void)
{
	list<char>		l;
	char			*str;
	char			*cmd;
	int			M;
	size_t			len;

	scanf("%s", str);
	for (len = strlen(str); len > 0; len--)
		l.push_front(str[len - 1]);
	free(str);
	list<char>::iterator	cs_iter = l.end();
	scanf("%d", &M);
	while (M--)
	{
		scanf("%s", &cmd);
		if (cmd[0] == 'L') ft_Left(&cs_iter, l.begin());
		else if (cmd[0] == 'D') ft_D(&cs_iter, l.end());
		else if (cmd[0] == 'B') ft_Backspace(cs_iter, &l);
		else if (cmd[0] == 'P') l.insert(cs_iter, cmd[2]);
		free(cmd);
	}
	free(tmp);
	for (itor = i.begin(); itor < i.end(); itor++)
		cout << *itor;
	return (0);
}
