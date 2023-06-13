/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:08:28 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/10 17:14:12 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_env_content(t_databus *data, char *content, char *name)
{
	int		i;
	char	*found_name;
	char	*equal_sign;

	i = 0;
	while (data->env[i])
	{
		found_name = ft_strnstr(data->env[i], name, STR_LIMIT);
		if (found_name)
		{
			equal_sign = ft_strchr(found_name, '=');
			ft_strlcpy(content, equal_sign + 1, STR_LIMIT);
			return ;
		}
		i++;
	}
}
