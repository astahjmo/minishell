/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:40:10 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/08 16:40:10 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_cmd(t_infoenv *env)
{
	int		i;
	t_env	**tmp;

	i = -1;
	while (++i < 1e4)
	{
		if (env->bucket[i] == NULL)
			continue ;
		tmp = &env->bucket[i];
		while (tmp)
		{
			printf("%s=%s\n", tmp[i]->key, tmp[i]->value);
			tmp = &(*tmp)->next;
		}
	}
}
