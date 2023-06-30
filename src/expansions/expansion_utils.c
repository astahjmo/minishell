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
	int		i;

	if (!str || !*str)
		return (NULL);
	i = 0;
	str++;
	if (!ft_isalpha(*str) && *str != '_')
		return (NULL);
	while (ft_isalnum(*str) || *str == '_')
	{
		name[i++] = *str;
		str++;
	}
	name[i] = '\0';
	return (ft_strdup(name));
}
