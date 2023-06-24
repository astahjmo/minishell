/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth <astaroth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:04:31 by astaroth          #+#    #+#             */
/*   Updated: 2023/05/15 15:11:31 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_token_string(t_tokens token)
{
	static char	*strings[10] = {
		"invalid",
		"<<",
		">>",
		"||",
		"&&",
		"|",
		"&",
		"<",
		">",
	};

	return (strings[token]);
}
