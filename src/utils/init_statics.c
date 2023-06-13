/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_statics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 23:14:39 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/13 16:52:17 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_lexemes(void)
{
	static char	*lexems[9] = {
		"<<",
		">>",
		"||",
		"&&",
		"|",
		"&",
		"<",
		">",
		NULL,
	};

	return (lexems);
}

char	**get_builtins(void)
{
	static char	*builtins[7] = {
		"exit",
		"env",
		"export",
		"define",
		"unset",
		NULL
	};

	return (builtins);
}

char	**get_expansion_lexes(void)
{
	static char	*expansions[3] = {
		"$",
		"~",
		"."
	};

	return (expansions);
}

t_fn_built_exec	**get_built_func(void)
{
	static t_fn_built_exec	*fns[7] = {
		exit_builtin,
		env_builtin,
		export_builtin,
		alt_env_builtin,
		unset_builtin,
		NULL,
	};

	return (fns);
}
