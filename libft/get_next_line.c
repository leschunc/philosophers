/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 20:33:20 by leschunc          #+#    #+#             */
/*   Updated: 2025/08/31 23:26:06 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*acc;
	ssize_t		valid;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	acc = NULL;
	while (1)
	{
		if (!*buf)
		{
			valid = read(fd, buf, BUFFER_SIZE);
			if (valid < 0)
				return (free(acc), NULL);
			if (valid == 0)
				return (acc);
			buf[valid] = '\0';
		}
		acc = ft_accumulator(acc, buf);
		if (!acc || ft_has_line(buf))
			break ;
		ft_movbuf(buf);
	}
	ft_movbuf(buf);
	return (acc);
}
