/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:53:05 by johmatos          #+#    #+#             */
/*   Updated: 2023/05/10 05:20:50 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

t_tokens	get_token(char *find)
{
	char	**tokens;
	int		count;

	tokens = ft_split(TOKENS, ' ');
	count = 0;
	while (tokens[count] != NULL)
	{
		if (ft_strncmp(find, tokens[count],
				ft_strlen(tokens[count])) == 0)
			return (count);
		count++;
	}
	return (-1);
}
