/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 03:25:23 by leschunc          #+#    #+#             */
/*   Updated: 2025/08/31 23:25:12 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	int		c;

	c = 0;
	count = 0;
	if (!s)
		return (-1);
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			c = ft_disp(args, s++);
			count += c;
		}
		else
			count += ft_putchar(*s);
		s++;
	}
	va_end(args);
	if (count < 0)
		return (-1);
	return (count);
}
