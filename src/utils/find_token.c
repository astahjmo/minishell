/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:53:05 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/04 07:36:11 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static char	**get_lexemes(void)
{
	static char	*lexems[9] = {
		"<<", // 0
		">>", // 1
		"||", // 2
		"&&", // 3
		"|", // 4
		"&", // 5
		"<", // 6
		">", // 7
		NULL, // 8
	};

	return (lexems);
}
static char	**get_expansion_lexes(void)
{
	static char	*expansions[3] = {
		"$",
		"~",
		"."
	};

	return (expansions);
}

t_tokens	get_expansion(char *line)
{
	int			idx;
	int			total_expansions;
	t_tokens	expansion;
	char		**expansions;

	idx = 0;
	expansion = T_INVALID;
	expansions = get_expansion_lexes();
	total_expansions = 3;
	while (idx < total_expansions && expansion == T_INVALID)
	{
		if (ft_strncmp(line, expansions[idx], ft_strlen(expansions[idx]) + 1) == 0)
			expansion = idx + 1;
		idx++;
	}
	return (expansion);
}

t_tokens	get_token(char *line)
{
	int			idx;
	int			total_lexems;
	t_tokens	lexem;
	char		**lexems;
	static int	ctx = 0;

	idx = 0;
	lexem = T_INVALID;
	ctx++;
	lexems = get_lexemes();
	total_lexems = 8;
	while (idx < total_lexems && lexem == T_INVALID && line && *line)
	{
		ft_printf("Context[%d] - %s\n", ctx, line);
		if (ft_strncmp(line, lexems[idx], ft_strlen(lexems[idx]) + 1) == 0)
			lexem = idx + 1;
		idx++;
	}
	return (lexem);
}
