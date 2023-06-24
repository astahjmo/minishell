/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:16:20 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/05 19:07:56 by johmatos         ###   ########.fr       */
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

void	string_eat_at(char **word, char at)
{
	char	*line;

	line = *word;
	while (*line != at)
		line++;
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

void	eat_token(char **word)
{
	char	*line;

	line = *word;
	while (line && *line != '\0' && get_token(line) != T_INVALID)
	{
		if (get_token(line) <= 3)
			line++;
		line++;
		break ;
	}
	*word = line;
}

void	string_eat_at_next_token(char **word)
{
	char	*line;
	char	*temp;

	line = *word;
	temp = line + 1;
	if (get_token(line) == -1)
	{
		if (*line == '\'' || *line == '"')
			string_eat_at(&temp, *line);
		else
			while (temp && *temp != '\0' && *temp != ' '
				&& get_token(temp) == -1 && get_expansion(temp) == -1)
				temp++;
		*word = temp;
	}
	else
		eat_token(word);
}
