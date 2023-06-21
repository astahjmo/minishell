/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unclosed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:38:21 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/21 18:58:46 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

int	string_is_equal(char *s1, char *s2)
{
	int	a;
	int	b;

	a = ft_strlen(s1);
	b = ft_strlen(s2);
	if (a != b)
		return (0);
	if (ft_strncmp(s1, s2, a + b) == 0)
		return (1);
	return (0);
}

int	check_unclosed_quotes(char *line, char *delimiter)
{
	int		credit;
	char	*cursor;

	credit = 0;
	cursor = ft_strnstr(line, delimiter, ft_strlen(line));
	if (cursor != NULL)
	{
		credit++;
		cursor++;
		while (*cursor != '\0' || cursor != NULL)
		{
			cursor = ft_strnstr(cursor, delimiter, ft_strlen(cursor));
			if (cursor == NULL)
				break ;
			cursor++;
			credit++;
		}
	}
	if (credit % 2 == 0)
		return (FALSE);
	return (TRUE);
}
