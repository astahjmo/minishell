/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_statics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 23:14:39 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/09 23:15:49 by johmatos         ###   ########.fr       */
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
		"echo",
		"cd",
		"pwd",
		"export",
		"unset",
		"env",
		"exit",
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
