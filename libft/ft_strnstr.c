/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:03:39 by leschunc          #+#    #+#             */
/*   Updated: 2025/08/31 18:30:06 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char	*little, size_t len)
{
	size_t	lenl;
	size_t	i;

	if (*little == '\0')
		return ((char *)big);
	lenl = ft_strlen(little);
	i = 0;
	while (big[i] && (len >= (lenl + i)))
	{
		if (!ft_strncmp(&big[i], little, lenl))
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
