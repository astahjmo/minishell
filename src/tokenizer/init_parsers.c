/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth <astaroth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:14:17 by johmatos          #+#    #+#             */
/*   Updated: 2023/05/15 12:23:41 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_fn_node_apply	**init_parser(void)
{
	static t_fn_node_apply	*fns[4] = {
		&tokenizer_operator,
		&tokenizer_string,
		NULL
	};

	return (fns);
}
