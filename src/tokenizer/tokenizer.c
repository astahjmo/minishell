/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:17:14 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/27 14:14:25 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

t_node	*create_token(char *line)
{
	t_node			*node;
	t_fn_node_apply	**parsers;
	int				count;

	node = NULL;
	parsers = init_parser();
	count = 0;
	if (!parsers)
		return (node);
	while (count <= 2 && node == NULL && parsers[count] != NULL)
		node = parsers[count++](line);
	return (node);
}

void	add_token_to_list(t_node *token, t_cmds *list)
{
	if (!list)
		return ;
	if (!token)
		return ;
	if (list->head == NULL)
		list->head = token;
	else
		list_add_back(list_last_node(list->head), token);
}

void	tokenizer(void)
{
	t_databus	*data;
	t_node		*node;
	char		*cursor;

	node = NULL;
	data = getter_data();
	cursor = data->stream;
	while (cursor && *data->stream != '\0')
	{
		if (is_whitespace(*cursor) && list_last_node(data->cmds->head)
			&& list_last_node(data->cmds->head)->token == T_SPACE)
			string_eat_all(&cursor, *cursor);
		if (*cursor == '#')
			string_eat_all(&cursor, '\n');
		if (*cursor == '\0')
			return ;
		node = create_token(cursor);
		if (node)
			add_token_to_list(node, data->cmds);
		string_eat_at_next_token(&cursor);
	}
}
