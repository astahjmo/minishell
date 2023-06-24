/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:51:05 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/24 15:58:44 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_node	*init_node(char *line)
{
	t_node	*node;

	node = list_node_new();
	node->token = T_WORD;
	node->str = line;
	node->next = NULL;
	return (node);
}

static t_node	*handler_dollar(char *cursor, char *line)
{
	t_node	*node;
	char	*str;

	if (!cursor)
		return (NULL);
	while (*cursor != '\0' && get_token(cursor) == -1 && *cursor != ' ')
		cursor++;
	str = ft_substr(line, 0, cursor - line);
	node = init_node(str);
	return (node);
}

t_node	*tokenizer_dollar(char *line)
{
	char	*cursor;
	t_node	*node;

	cursor = line;
	if (!cursor)
		return (NULL);
	node = handler_dollar(cursor, line);
	return (node);
}
