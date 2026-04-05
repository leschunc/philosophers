#include "philo.h"

void	atoiv(int a_len, char const *argv[], int *set)
{
	int	i;

	i = 0;
	while (i < a_len)
	{
		set[i] = ft_atoi(argv[i]);
		i++;
	}
}

void	disp_args(int arg_len, int *set)
{
	static char	*disp[] = (char *[]){S_NUM, S_DIE, S_EAT, S_REST, S_CYCLE, NULL};
	int			i;

	i = 0;
	while (i < arg_len)
	{
		printf("[%i][%s]\n", set[i], disp[i]);
		i++;
	}
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
