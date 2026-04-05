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

// 	if (arg[0] == EMPTY_ARG)
// 		return (NULL);
// 	trimmed = ft_strtrim(arg, " \t");
// 	if (trimmed[0] == EMPTY_ARG)
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
// 		if (argv[i][0] == EMPTY_ARG)
// 			return (false);
// 		converted = to_valid_arg(*(argv + i));
// 		if (converted == NULL)
// 			return (false);
// 		i++;
// 	}
// 	return (true);
// }

void	atoiv(int argc, char const *argv[], int *set)
{
	int	i;

	i = 0;
	while (i < SET_SIZE)
	{
		set[i] = ft_atoi(argv[i]);
		i++;
	}
}

int	main(int argc, char const *argv[])
{
	int	set[SET_SIZE];
	int	i;

	if (SET_SIZE != 4)
		return (1);
	atoiv(argc, argv + 1, set);
	prepare_sim();
	run_simulation();
}
