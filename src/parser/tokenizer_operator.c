/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_operator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 01:15:00 by johmatos          #+#    #+#             */
/*   Updated: 2023/05/10 05:19:36 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

t_node	*tokenizer_operator(char *str)
{
	t_tokens	token;
	t_node		*node;

	token = get_token(str);
	if (token == -1)
		return (NULL);
	node = malloc(sizeof(t_node));
	return (token);
}
