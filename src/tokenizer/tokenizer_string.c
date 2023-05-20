/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:11:15 by astaroth          #+#    #+#             */
/*   Updated: 2023/05/20 07:34:04 by johmatos         ###   ########.fr       */
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
	char	*start;
	char	*sub;
	char	*key;
	t_node	*node;

	start = cursor;
	sub = NULL;
	final = ft_strchr(++cursor, '"');
	while (cursor != final && get_expansion(cursor) == -1)
		cursor++;
	if (get_expansion(cursor) != -1)
		sub = ft_substr(start, 0, cursor - start);
	key = trim_key(cursor);
	str = ft_interpol("%s%s%s", sub, get_env(key));
	node = init_node(str);
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
	

	cursor = line;
	node = NULL;
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