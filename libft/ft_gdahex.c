/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gdahex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 03:30:19 by leschunc          #+#    #+#             */
/*   Updated: 2025/08/31 23:25:41 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_gdahex(unsigned int nb)
{
	char			*str;
	unsigned int	count;

	count = 0;
	str = "0123456789ABCDEF";
	if (nb > 15)
		count += ft_gdahex(nb / 16);
	count += ft_putchar(str[nb % 16]);
	return (count);
}
