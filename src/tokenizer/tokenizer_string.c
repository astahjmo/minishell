/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:11:15 by astaroth          #+#    #+#             */
/*   Updated: 2023/05/23 17:51:09 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static t_node	*init_node(char*line)
{
	t_node	*node;

	node = ft_node_new();
	node->token = T_WORD;
	node->data = line;
	node->next = NULL;
	node->back = NULL;
	return (node);
}

static t_node	*handler_word(char *cursor, char *line)
{
	t_node	*node;
	char	*str;

	while (get_token(cursor) == -1 && *cursor != ' '
		&& get_expansion(cursor) == -1)
		cursor++;
	str = ft_substr(line, 0, cursor - line);
	node = init_node(str);
	return (node);
}

t_node	*handler_double_quotes(char *cursor)
{
	char	*final;
	char	*str;
	char	*join;
	t_node	*node;

	final = ft_strchr(++cursor, '"');
	str = ft_substr(cursor, 0, final - cursor);
	join = expand_dolar(str);
	node = init_node(join);
	return (node);
}

t_node	*handler_single_quotes(char *cursor)
{
	char	*final;
	char	*str;
	t_node	*node;

	final = ft_strchr(++cursor, '\'');
	str = ft_substr(cursor, 0, final - cursor);
	node = init_node(str);
	return (node);
}

t_node	*tokenizer_string(char *line)
{
	char		*cursor;
	t_node		*node;

	cursor = line;
	if (!cursor)
		return (NULL);
	if (*line == '\'') 
		node = handler_single_quotes(cursor);
	else if (*line == '"')
		node = handler_double_quotes(cursor);
	else
		node = handler_word(cursor, line);
	return (node);
}