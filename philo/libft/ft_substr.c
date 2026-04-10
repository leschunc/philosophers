/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:38:35 by leschunc          #+#    #+#             */
/*   Updated: 2025/08/31 18:30:21 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	total;
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	if (start >= (ft_strlen(s)))
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) > len)
		total = len;
	else
		total = ft_strlen(&s[start]);
	i = 0;
	res = malloc(total + 1);
	if (!res)
		return (res);
	while (total && s[start + i])
	{
		res[i] = s[start + i];
		total--;
		i++;
	}
	res[i] = '\0';
	return (res);
}
