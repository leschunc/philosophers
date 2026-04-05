/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 03:25:07 by leschunc          #+#    #+#             */
/*   Updated: 2025/08/31 23:27:24 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nb)
{
	char	c;
	int		count;

	count = 0;
	if (nb == -2147483648)
	{
		return (count += ft_putstr("-2147483648"));
	}
	if (nb < 0)
	{
		nb *= -1;
		count += ft_putchar('-');
	}
	if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
	}
	c = (nb % 10) + '0';
	count += ft_putchar(c);
	return (count);
}
