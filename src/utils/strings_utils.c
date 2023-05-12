/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:16:20 by johmatos          #+#    #+#             */
/*   Updated: 2023/05/12 02:33:09 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	string_eat_until(char **word, char *until)
{
	char	*line;

	line = *word;
	while (ft_strncmp(line, until, ft_strlen(until)) == 0)
		line++;
	*word = line;
}

void	string_eat_all(char **word, char hungry)
{
	char	*line;

	line = *word;
	while (*line == hungry)
		line++;
	*word = line;
}

t_bool	string_is_equal(char *string, char find)
{
	return (*string == find);
}

void	string_eat_at_next_token(char **word)
{
	
	char *line;

	line = *word;

	if (get_token(line) == -1)
	{
		while (line && *line != '\0'
			&& get_token(line) == -1)
			line++;
	}
	else
	{
		while (line && *line != '\0' && get_token(line) != -1)
		{
			if (get_token(line) <= 3)
				line++;
			line++;
			break ;
		}
	}
	*word = line;
}
