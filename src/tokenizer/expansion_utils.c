/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:06:59 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/26 22:14:06 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_name(char *str)
{
	char	name[STR_LIMIT];

	if (!str)
		return (NULL);
	str++;
	if (!ft_isalpha(*str) && *str != '_')
		return (NULL);
	while (ft_isalnum(*str) || *str == '_')
	{
		name[ft_strlen(name)] = *str;
		str++;
	}
	return (ft_strdup(name));
}
