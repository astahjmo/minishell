/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:04:31 by astaroth          #+#    #+#             */
/*   Updated: 2023/06/28 16:44:43 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_token_string(t_tokens token)
{
	static char	*strings[11] = {
		"invalid",
		"<<",
		">>",
		"||",
		"&&",
		"|",
		"&",
		"<",
		">",
		"<word>",
		"<space>"
	};

	return (strings[token]);
}
