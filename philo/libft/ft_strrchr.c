/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:16:56 by leschunc          #+#    #+#             */
/*   Updated: 2025/08/31 18:30:12 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char	*s, int c)
{
	int				i;
	unsigned char	chr;

	chr = c;
	i = ft_strlen(s);
	while (i >= 0 && s[i] != chr)
		i--;
	if (s[i] == chr)
		return ((char *)&s[i]);
	return (NULL);
}
