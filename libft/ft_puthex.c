/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 03:27:57 by leschunc          #+#    #+#             */
/*   Updated: 2025/08/31 23:27:28 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(unsigned int nb)
{
	char			*str;
	unsigned int	count;

	count = 0;
	str = "0123456789abcdef";
	if (nb > 15)
		count += ft_puthex(nb / 16);
	count += ft_putchar(str[nb % 16]);
	return (count);
}
