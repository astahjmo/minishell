/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_expansions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 05:32:09 by johmatos          #+#    #+#             */
/*   Updated: 2023/05/25 18:52:58 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_dolar(char *line)
{
	char	*start;
	char	*final;
	char	*key;
	char	*str;

	start = ft_strchr(line, '$');
	final = start;
	if (start == NULL)
		return (NULL);
	start++;
	while(*final != '\0' && *final != ' ' && get_token(line) == -1
		&& get_expansion(line) == -1)
		final++;
	key = ft_substr(start, 0, final - start);
	str = get_env(key);
	free(key);
	return (str);
}
