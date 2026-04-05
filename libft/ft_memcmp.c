/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:35:44 by leschunc          #+#    #+#             */
/*   Updated: 2025/08/31 18:28:21 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*str1;
	const char	*str2;

	if (n == 0)
		return (0);
	str1 = (const char *)s1;
	str2 = (const char *)s2;
	while (!ft_strncmp(str1, str2, 1) && --n)
	{
		str1++;
		str2++;
	}
	return (ft_strncmp(str1, str2, 1));
}
