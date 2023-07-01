/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:09:07 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/07/01 11:11:35 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*next_whitespace(char *str, char c);
static char	*next_valid_char(char *str, char c);
static int	word_counter(char *s, char c);

t_split	*split_envp(char *str, char c)
{
	int		index;
	t_split	*ptr;

	index = 0;
	ptr = malloc(sizeof(t_split));
	ptr->word_count = word_counter(str, c);
	ptr->str_arr = ft_calloc(sizeof(char *), (ptr->word_count + 1));
	ptr->str_arr[ptr->word_count] = NULL;
	while (*str && index < (int)ptr->word_count - 1)
	{
		str = next_valid_char(str, c);
		if (*str)
		{
			ptr->str_arr[index++] = str;
			str = next_whitespace(str, c);
			*str++ = '\0';
		}
	}
	return (ptr);
}

static char	*next_whitespace(char *str, char c)
{
	while (*str != '\0' && *str != c)
		str++;
	return (str);
}

static char	*next_valid_char(char *str, char c)
{
	while (*str == c)
		str++;
	return (str);
}

static int	word_counter(char *s, char c)
{
	int		counter;
	char	state;

	state = 0;
	counter = 0;
	while (*s)
	{
		if (*s != c && state == 0)
		{
			state = 1;
			counter++;
		}
		else if (*s == c)
			state = 0;
		s++;
	}
	return (counter);
}
