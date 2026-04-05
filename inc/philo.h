#ifndef PHILO_H
# define PHILO_H

# include "libft.h"
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

# define EMPTY '\0'
# define NUM "number_of_philosophers"
# define DIE "time_to_die"
# define EAT "time_to_eat"
# define REST "time_to_sleep"
# define CYCLE "number_of_times_each_philosopher_must_eat"

void	safe_free(char **ptr);
void	atoiv(int argc, char const *argv[], int *set);
void	disp_args(int argc, int *set);

#endif