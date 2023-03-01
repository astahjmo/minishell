/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:17:14 by johmatos          #+#    #+#             */
/*   Updated: 2023/03/01 01:03:22 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	  generic_checker(char *token)
{
	char **g_typearr;
	int		count;

	count = 0;
	g_typearr = ft_split(TOKENS, ' ');
	while (g_typearr[count])
	{
		if (ft_strncmp(g_typearr[count], token, ft_strlen(token) +
			ft_strlen(g_typearr[count])) == 0)
			return (count);
		count++;
	}
	free(g_typearr);
	return (-1);
}

void line_analysis(char *line)
{
	char **tokens;
	int count;
	int type;
	t_tokens *list_tokens;
	t_tokens *cursor;

	tokens = ft_split(line,' ');
	list_tokens = malloc(sizeof(t_tokens));
	cursor = list_tokens;
	count = 0;
	while (tokens[count])
	{
		type = generic_checker(tokens[count]);
		cursor->type = type;
		cursor->word = tokens[count];
		count++;
		if (tokens[count])
		{
			cursor->next = malloc(sizeof(t_tokens));
			cursor = cursor->next;
		}
		else
			cursor->next = NULL;
	}
	cursor = list_tokens;
}
