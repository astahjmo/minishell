/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 01:22:27 by johmatos          #+#    #+#             */
/*   Updated: 2023/05/13 02:48:02 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

t_node	*tokenizer_string(char *line)
{
	t_tokens	token;
	char		*delimiter;
	char		*word;
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
