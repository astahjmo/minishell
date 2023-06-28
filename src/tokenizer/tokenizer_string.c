/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:11:15 by astaroth          #+#    #+#             */
/*   Updated: 2023/06/28 15:36:19 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static t_node	*init_node(char *line)
{
	t_node	*node;

	node = list_node_new();
	if (*line == '\0')
		node->token = T_SPACE;
	else
		node->token = T_WORD;
	if (node->token == T_SPACE)
		node->str = ft_strdup(" ");
	else
		node->str = line;
	node->next = NULL;
	return (node);
}

static t_node	*handler_word(char *cursor, char *line)
{
	t_node	*node;
	char	*str;

	if (!cursor)
		return (NULL);
	while (*cursor != '\0' && get_token(cursor) == -1
		&& *cursor != ' ' && *cursor != '\'' && *cursor != '"')
		cursor++;
	str = ft_substr(line, 0, cursor - line);
	node = init_node(str);
	return (node);
}

t_node	*handler_double_quotes(char *cursor)
{
	char	*final;
	char	*str;
	t_node	*node;

	final = ft_strchr(cursor + 1, '"');
	str = ft_substr(cursor, 0, 1 + final - cursor);
	node = init_node(str);
	return (node);
}

t_node	*handler_single_quotes(char *cursor)
{
	char	*final;
	char	*str;
	t_node	*node;

	final = ft_strchr(cursor + 1, '\'');
	str = ft_substr(cursor, 0, 1 + final - cursor);
	node = init_node(str);
	return (node);
}

t_node	*tokenizer_string(char *line)
{
	char	*cursor;
	t_node	*node;

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
