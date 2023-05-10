/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:17:14 by johmatos          #+#    #+#             */
/*   Updated: 2023/05/10 04:22:37 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
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
	while (count < 3 && node == NULL && parsers[count] != NULL)
		node = parsers[count++](line);
	return (node);
}

void	tokenizer(t_databus data)
{
	int			state;
	int			token;
	t_node		*node;

	state = 0;
	token = 0;
	while (data.stream && *data.stream != '\0' && g_table[state][token] != -1)
	{
		if (string_is_equal(data.stream, ' '))
			string_eat_until(&data.stream, " ");
		if (string_is_equal(data.stream, '#'))
			string_eat_all(&data.stream, '\n');
		node = create_token(data.stream);
		token = node->token - 1;
		state = g_table[state][token];
		ft_printf("STRING: %s\nToken: %d\n State: %d\ntable: %d\n", data.stream, token,state, g_table[state][token]);
		string_eat_at_next_token(&data.stream);
	}
}
