/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:17:14 by johmatos          #+#    #+#             */
/*   Updated: 2023/02/23 14:40:02 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	  generic_checker(char *token, char *gtype)
{
	char **g_typearr;
	int		count;

	count = 0;
	g_typearr = ft_split(gtype, ' ');
	while (g_typearr[count])
	{
		if (ft_strncmp(g_typearr[count], token, ft_strlen(token) +
			ft_strlen(g_typearr[count])))
			return (1);
		count++;
	}
	free(g_typearr);
	return (0);
}

void line_analysis(char *line)
{
	char **tokens;
	int count;

	tokens = ft_split(line,' ');
	count = 0;
	while (tokens[count]) {
		if (generic_checker(tokens[count], COPERATOR))
			;
		else if (generic_checker(tokens[count], OPERATOR))
			;
		else if (generic_checker(tokens[count], BUILTIN))
			;
		else
			;
	}
}
