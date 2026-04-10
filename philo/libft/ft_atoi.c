/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:41:39 by leschunc          #+#    #+#             */
/*   Updated: 2025/08/31 18:27:51 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (((c >= 9) && (c <= 13)) || (c == ' '))
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	char	*ptr;
	int		result;
	int		sl;

	result = 0;
	sl = 1;
	ptr = (char *)nptr;
	while (ft_isspace(*ptr))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sl = -1;
		ptr++;
	}
	while (ft_isdigit(*ptr))
	{
		result = (result * 10) + (*ptr - '0');
		ptr++;
	}
	return (result * sl);
}
