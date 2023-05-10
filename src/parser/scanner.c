/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:17:14 by johmatos          #+#    #+#             */
/*   Updated: 2023/05/10 05:33:00 by johmatos         ###   ########.fr       */
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
	if (string_is_equal(data.stream, ' '))
		string_eat_until(&data.stream, " ");
	if (string_is_equal(data.stream, '#'))
		string_eat_all(&data.stream, '\n');
	if (*data.stream != '\0' && data.stream != NULL)
	node = create_token(data.stream);
}
