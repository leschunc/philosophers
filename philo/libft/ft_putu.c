/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 03:30:42 by leschunc          #+#    #+#             */
/*   Updated: 2025/08/31 23:27:15 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putu(unsigned int nb)
{
	char	c;
	int		count;

	count = 0;
	if (nb > 9)
		count += ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	count += ft_putchar(c);
	return (count);
}
