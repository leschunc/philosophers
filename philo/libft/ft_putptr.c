/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 03:28:44 by leschunc          #+#    #+#             */
/*   Updated: 2025/08/31 23:27:22 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_longhex(unsigned long nb)
{
	char			*str;
	unsigned int	count;

	count = 0;
	str = "0123456789abcdef";
	if (nb > 15)
		count += ft_longhex(nb / 16);
	count += ft_putchar(str[nb % 16]);
	return (count);
}

int	ft_putptr(unsigned long i)
{
	int	count;

	count = 0;
	if (i)
	{
		count += ft_putstr("0x");
		count += ft_longhex(i);
	}
	else
		count += ft_putstr("(nil)");
	return (count);
}
