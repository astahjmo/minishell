/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth <astaroth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:14:17 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/04 06:33:09 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_fn_node_apply	**init_parser(void)
{
	static t_fn_node_apply	*fns[3] = {
		&tokenizer_operator,
		&tokenizer_string,
		NULL
	};

	return (fns);
}
