#include "philo.h"

void	safe_free(char **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}
