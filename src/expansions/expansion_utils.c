/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:06:59 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/30 22:59:46 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_name(char *str)
{
	char	name[STR_LIMIT];
	int		i;

	if (!str || !*str)
		return (NULL);
	i = 0;
	str++;
	if (!ft_isalpha(*str) && *str != '_')
		return (NULL);
	while (ft_isalnum(*str) || *str == '_')
	{
		name[i++] = *str;
		str++;
	}
	name[i] = '\0';
	return (ft_strdup(name));
}

char	*handle_frees(char *tmp, char *new_line, char *line, int has_dollar)
{
	free(tmp);
	if (!has_dollar)
	{
		free(new_line);
		return (line);
	}
	getter_data()->exit_status = 0;
	free(line);
	return (new_line);
}

int	count_quotes(char *list_str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (list_str[i])
	{
		if (list_str[i] == '"')
			count++;
		i++;
	}
	return (count);
}

static void	copy_str(char *list_str, char *new_str)
{
	if (*list_str == '\'')
	{
		while (*list_str)
		{
			if (*list_str != '\'')
				*new_str++ = *list_str;
			list_str++;
		}
	}
	else
	{
		while (*list_str)
		{
			if (*list_str != '"')
				*new_str++ = *list_str;
			list_str++;
		}
	}
}

char	*remove_quotes(char *list_str)
{
	int		len;
	int		count;
	char	*new_str;

	count = count_quotes(list_str);
	len = ft_strlen(list_str) - count;
	new_str = ft_calloc(sizeof(char), (len + 1));
	copy_str(list_str, new_str);
	free(list_str);
	return (new_str);
}
