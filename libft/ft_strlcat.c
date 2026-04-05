/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:57:19 by leschunc          #+#    #+#             */
/*   Updated: 2025/10/25 13:25:03 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char *src, size_t size)
{
	size_t	ds;
	size_t	ss;
	size_t	i;
	size_t	steps;

	ds = ft_strlen(dst);
	ss = ft_strlen(src);
	if (size == 0)
		return (ss);
	if (size <= ds)
		return (size + ss);
	steps = size - (ds + 1);
	i = 0;
	while ((steps > 0) && src[i])
	{
		dst[ds + i] = src[i];
		i++;
		steps--;
	}
	dst[ds + i] = '\0';
	return (ds + ss);
}
