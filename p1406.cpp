#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

void	ft_Left(list<int>::iterator *cs_iter, list<int>::iterator begin_iter)
{
	if (*cs_iter != begin_iter) (*cs_iter)--;
	return ;
}

void	ft_D(list<int>::iterator *cs_iter, list<int>::iterator end_iter)
{
	if (*cs_iter != end_iter) (*cs_iter)++;
	return ;
}

void	ft_Backspace(list<int>::iterator cs_iter, list<int> *l)
{
	if (cs_iter == (*l).begin()) return ;
	cs_iter--;
	(*l).erase(cs_iter);
	return ;
}

int	main(void)
{
	list<int>		l;
	char			*str;
	char			*tmp;
	char			*cmd;
	int			M;
	size_t			len;

	str = NULL;
	tmp = NULL;
	getline(&str, 0, 0);
	for (len = strlen(str); len > 0; len--)
		l.push_front(str[len - 1]);
	free(str);
	list<int>::iterator	cs_iter = l.end();
	getline(&tmp, 0, 0);
	for (M = atoi(tmp); M > 0; M--)
	{
		cmd = NULL;
		getline(&cmd, 0, 0);
		if (strlen(cmd) == 0) return (0);
		if (cmd[0] == 'L') ft_Left(&cs_iter, l.begin());
		else if (cmd[0] == 'D') ft_D(&cs_iter, l.end());
		else if (cmd[0] == 'B') ft_Backspace(cs_iter, &l);
		else if (cmd[0] == 'P') l.insert(cs_iter, cmd[2]);
		free(cmd);
	}
	free(tmp);
	return (0);
}
