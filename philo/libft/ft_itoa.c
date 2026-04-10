/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:34:07 by leschunc          #+#    #+#             */
/*   Updated: 2025/08/31 18:28:17 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*rev(char *str)
{
	char	*buff;
	int		strl;
	int		i;

	strl = ft_strlen(str);
	buff = malloc(strl + 1);
	if (!buff)
		return (NULL);
	i = 0;
	while (str[i])
	{
		buff[i] = str[strl - 1 - i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

char	*ft_itoa(int n)
{
	int		sg;
	int		i;
	char	buff[12];

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sg = 1;
	if (n < 0)
	{
		sg = -1;
		n *= -1;
	}
	i = 0;
	while (n > 9)
	{
		buff[i++] = n % 10 + '0';
		n /= 10;
	}
	buff[i++] = n % 10 + '0';
	if (sg == -1)
		buff[i++] = '-';
	buff[i] = '\0';
	return (rev(buff));
}
