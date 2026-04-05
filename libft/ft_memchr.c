/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:10:38 by leschunc          #+#    #+#             */
/*   Updated: 2025/08/31 18:28:19 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*arr;

	arr = (unsigned char *)s;
	c = (unsigned char)c;
	while (n--)
	{
		if (*arr == c)
		{
			return (arr);
		}
		arr++;
	}
	return (NULL);
}
