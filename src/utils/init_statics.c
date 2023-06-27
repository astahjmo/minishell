/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_statics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 23:14:39 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/24 23:17:55 by vcedraz-         ###   ########.fr       */
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
	static char	*builtins[9] = {
		"exit",
		"env",
		"export",
		"define",
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
	static t_fn_built_exec	*fns[9] = {
		exit_builtin,
		env_builtin,
		export_builtin,
		alt_env_builtin,
		unset_builtin,
		echo_builtin,
		pwd_builtin,
		cd_builtin,
		NULL,
	};

	return (fns);
}
