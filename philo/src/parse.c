#include "philo.h"

void	atoiv(t_context *c)
{
	int	i;

	i = 0;
	while (i < c->arr_len)
	{
		c->set[i] = ft_atoi(c->argv[i + 1]);
		i++;
	}
	if (c->set[NUM] > 4000)
	{
		printf("CAPTCHA: name all %ld philosophers to use this many resources\n", c->set[NUM]);
		exit (ERR);
	}
	// set set[arrlen] = 0?
}

// void	disp_args(t_context *c)
// {
// 	static char	*disp[] = (char *[]){S_NUM, S_DIE, S_EAT, S_REST, S_CYCLE,
// 			NULL};
// 	int			i;

// 	i = 0;
// 	while (i < c->arr_len)
// 	{
// 		ft_printf("[%ld]\t[%s]\n", c->set[i], disp[i]);
// 		i++;
// 	}
// }

// char	*to_valid_arg(char *arg)
// {
// 	char	*trimmed;

// 	if (arg[0] == EMPTY)
// 		return (NULL);
// 	trimmed = ft_strtrim(arg, " \t");
// 	if (trimmed[0] == EMPTY)
// 		return (safe_free(&trimmed), NULL);
// 	return (trimmed);
// }

// bool	is_valid_argv(int arr_len, char *argv[])
// {
// 	int		i;
// 	char	*converted;

// 	if (arr_len != 5 && arr_len != 6)
// 		return (NULL);
// 	i = 0;
// 	while (argv[i])
// 	{
// 		if (argv[i][0] == EMPTY)
// 			return (false);
// 		converted = to_valid_arg(*(argv + i));
// 		if (converted == NULL)
// 			return (false);
// 		i++;
// 	}
// 	return (true);
// }
