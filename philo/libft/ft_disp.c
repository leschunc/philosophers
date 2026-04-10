/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 03:27:11 by leschunc          #+#    #+#             */
/*   Updated: 2025/08/31 23:25:37 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_disp(va_list args, const char *c)
{
	if (*(c + 1) == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (*(c + 1) == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (*(c + 1) == 'p')
		return (ft_putptr(va_arg(args, long)));
	if (*(c + 1) == 'd' || *(c + 1) == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (*(c + 1) == 'u')
		return (ft_putu(va_arg(args, int)));
	if (*(c + 1) == 'x')
		return (ft_puthex(va_arg(args, int)));
	if (*(c + 1) == 'X')
		return (ft_gdahex(va_arg(args, int)));
	if (*(c + 1) == '%')
		return (ft_putchar('%'));
	return (-1);
}
