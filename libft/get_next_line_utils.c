/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 20:31:46 by leschunc          #+#    #+#             */
/*   Updated: 2025/08/31 23:26:04 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_linelen(const char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			i++;
	}
	return (i);
}

int	ft_has_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i++] == '\n')
		return (i);
	return (0);
}

char	*ft_accumulator(char *acc, char *buf)
{
	int		i;
	int		j;
	char	*new;

	new = malloc(ft_linelen(acc) + ft_linelen(buf) + 1);
	if (!new)
		return (ft_safe_free(acc), NULL);
	i = 0;
	while (acc && acc[i])
	{
		new[i] = acc[i];
		i++;
	}
	ft_safe_free(acc);
	j = 0;
	while (buf[j])
	{
		new[i + j] = buf[j];
		if (buf[j++] == '\n')
			break ;
	}
	new[j + i] = '\0';
	if (!*new)
		return (NULL);
	return (new);
}

void	ft_movbuf(char *buf)
{
	int	i;
	int	j;

	i = ft_linelen(buf);
	j = 0;
	while (buf[i])
	{
		buf[j] = buf[i];
		j++;
		i++;
	}
	while (j < (BUFFER_SIZE + 1))
		buf[j++] = '\0';
}
