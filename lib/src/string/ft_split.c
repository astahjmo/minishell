/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos < johmatos@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:18:53 by johmatos          #+#    #+#             */
/*   Updated: 2022/10/30 13:32:31 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		free (str[count]);
		str[count++] = NULL;
	}
	free(str);
}

static int	ft_count(const char *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			words++;
		while (*s && (*s != c))
			s++;
	}
	return (words);
}

static char	**ft_alloc_str(char **split, char *s, int words, char c)
{
	int		start;
	int		end;
	int		index;

	start = 0;
	index = 0;
	while (index < words)
	{
		while (s[start] == c)
			start += 1;
		end = start;
		while (s[end] != c && s[end])
			end += 1;
		split[index] = (char *)ft_calloc((end - start) + 1, sizeof(char));
		if (!split[index])
		{
			ft_free(split);
			return (NULL);
		}
		ft_strlcpy(split[index], s + start, (end - start) + 1);
		start = end;
		index++;
	}
	return (split);
}

char	**ft_split(const char *s, char c)
{
	int		word;
	char	**str;

	if (!s && !(*s))
		return (NULL);
	word = ft_count(s, c);
	str = malloc(sizeof(char *) * (word + 1));
	if (!str)
		return (NULL);
	str = ft_alloc_str(str, (char *)s, word, c);
	if (!str)
		return (NULL);
	str[word] = NULL;
	return (str);
}
