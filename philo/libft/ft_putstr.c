/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 03:24:10 by leschunc          #+#    #+#             */
/*   Updated: 2025/08/31 23:27:17 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (str)
	{
		while (*str)
		{
			count += ft_putchar(*str);
			str++;
		}
	}
	else
		count += ft_putstr("(null)");
	return (count);
}
