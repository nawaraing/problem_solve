#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_Left(ssize_t *cs);
void	ft_D(ssize_t *cs, ssize_t N);
void	ft_Backspace(ssize_t *cs, ssize_t *N, char **str);
void	ft_Press(ssize_t *cs, ssize_t *N, char **str, char put);

int		main(void)
{
	char	*str;
	char	*tmp;
	char	*cmd;
	ssize_t	N, cs;
	int		M;

	str = NULL;
	tmp = NULL;
	N = getline(&str, 0, 0);
	cs = N;
	getline(&tmp, 0, 0);
	for (M = atoi(tmp); M > 0; M--)
	{
		cmd = NULL;
		getline(&cmd, 0, 0);
		if (cmd[0] == 'L') ft_Left(&cs);
		else if (cmd[0] == 'D') ft_D(&cs, N);
		else if (cmd[0] == 'B') ft_Backspace(&cs, &N, &str);
		else if (cmd[0] == 'P') ft_Press(&cs, &N, &str, cmd[2]);
		free(cmd);
	}
	free(tmp);
	free(str);
	return (0);
}

void	ft_Left(ssize_t *cs)
{
	if (*cs != 0) (*cs)--;
	return ;
}

void	ft_D(ssize_t *cs, ssize_t N)
{
	if (*cs != N) (*cs)++;
	return ;
}

void	ft_Backspace(ssize_t *cs, ssize_t *N, char **str)
{
	if (*cs == 0) return ;
	(*cs)--;
	(*str)[(*cs)] = 0;
	strcat(*str, &((*str)[(*cs) + 1]));
	(*N)--;
	return ;
}

void	ft_Press(ssize_t *cs, ssize_t *N, char **str, char put)
{
	char	*tmp;

	if (*cs == *N)
	{
		tmp = realloc(*str, (*cs) + 2);
		free(*str);
		*str = tmp;
		tmp = strdup("");
	}
	else tmp = strdup(&((*str)[(*cs)]));
	(*str)[(*cs)] = put;
	(*str)[(*cs) + 1] = 0;
	strcat((*str), tmp);
	free(tmp);
	(*N)++;
	(*cs)++;
	return ;
}
