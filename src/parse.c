#include "philo.h"

void	safe_free(char **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}

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

// bool	is_valid_argv(int argc, char *argv[])
// {
// 	int		i;
// 	char	*converted;

// 	if (argc != 5 && argc != 6)
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

void	atoiv(int arg_num, char const *argv[], int *set)
{
	int	i;

	i = 0;
	while (i < arg_num)
	{
		set[i] = ft_atoi(argv[i]);
		i++;
	}
}

void	disp_args(int arg_len, int *set)
{
	static char	*disp[] = (char *[]){NUM, DIE, EAT, REST, CYCLE, NULL};
	int			i;

	i = 0;
	while (i < arg_len)
	{
		printf("[%i][%s]\n", set[i], disp[i]);
		i++;
	}
}
