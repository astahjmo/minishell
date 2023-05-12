/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:14:17 by johmatos          #+#    #+#             */
/*   Updated: 2023/05/10 01:31:22 by johmatos         ###   ########.fr       */
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
