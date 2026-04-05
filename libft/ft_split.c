/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 05:31:45 by leschunc          #+#    #+#             */
/*   Updated: 2025/10/21 01:26:51 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	freew(char **arr, int i)
{
	while (i > 0)
	{
		free(arr[i - 1]);
		i--;
	}
	free(arr);
}

static char	*walloc(const char **s, char c)
{
	char		*word;
	int			size;
	const char	*str;

	size = 0;
	str = *s;
	while (*str == c)
		str++;
	while (*str && c != *str)
	{
		str++;
		size++;
	}
	word = malloc(size + 1);
	if (!word)
		return (NULL);
	str -= size;
	size = 0;
	while (*str && *str != c)
		word[size++] = *str++;
	word[size] = '\0';
	*s = str;
	return (word);
}

static unsigned int	wordcount(char const *s, char c)
{
	int	inword;
	int	wordcount;
	int	i;

	i = 0;
	wordcount = 0;
	inword = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (inword == 0)
				wordcount++;
			inword = 1;
		}
		else
			inword = 0;
		i++;
	}
	return (wordcount);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		wc;
	int		i;

	wc = wordcount(s, c);
	arr = malloc((wc + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr[wc] = NULL;
	i = 0;
	while (i < wc)
	{
		arr[i] = walloc(&s, c);
		if (!arr[i])
		{
			freew(arr, i);
			return (NULL);
		}
		i++;
	}
	return (arr);
}
