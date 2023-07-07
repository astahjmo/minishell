/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_statics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 23:14:39 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/27 18:30:44 by johmatos         ###   ########.fr       */
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
	static char	*builtins[8] = {
		"exit",
		"env",
		"export",
		"unset",
		"echo",
		"pwd",
		"cd",
		NULL
	};

	return (builtins);
}

char	**get_expansion_lexes(void)
{
	static char	*expansions[2] = {
		"$",
		"~",
	};

	return (expansions);
}

t_fn_built_exec	**get_built_func(void)
{
	static t_fn_built_exec	*fns[7] = {
		exit_builtin,
		env_builtin,
		export_builtin,
		unset_builtin,
		echo_builtin,
		pwd_builtin,
		cd_builtin,
	};

	return (fns);
}
