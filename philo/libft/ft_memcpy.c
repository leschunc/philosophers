/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:55:09 by leschunc          #+#    #+#             */
/*   Updated: 2025/08/31 18:28:23 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*result;
	unsigned char	*srcp;
	size_t			i;

	srcp = (unsigned char *)src;
	result = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		result[i] = srcp[i];
		i++;
	}
	return (dest);
}
