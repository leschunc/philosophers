/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:56:49 by leschunc          #+#    #+#             */
/*   Updated: 2025/08/31 18:29:22 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		size;

	size = ft_strlen(s);
	dup = malloc((size + 1) * (sizeof(char)));
	if (!dup)
		return (NULL);
	while (*s)
	{
		*dup = *s;
		dup++;
		s++;
	}
	*dup = '\0';
	dup -= size;
	return (dup);
}
