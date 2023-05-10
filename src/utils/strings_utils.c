/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:16:20 by johmatos          #+#    #+#             */
/*   Updated: 2023/05/10 05:21:40 by johmatos         ###   ########.fr       */
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
