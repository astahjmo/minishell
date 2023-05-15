/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth <astaroth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:11:15 by astaroth          #+#    #+#             */
/*   Updated: 2023/05/15 16:11:19 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

t_node	*tokenizer_string(char *line)
{
	char		*delimiter;
	t_node		*node;

	delimiter = line;
	while (delimiter != NULL && *delimiter != '\0'
		&& get_token(delimiter) == -1)
		delimiter++;
	node = ft_node_new();
	node->token = T_WORD;
	node->data = line;
	node->length = delimiter - line;
	node->next = NULL;
	node->back = NULL;
	return (node);
}
