/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_linked_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth <astaroth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:42:42 by astaroth          #+#    #+#             */
/*   Updated: 2023/05/16 15:07:38 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_env_back(t_env *node, t_env *new)
{
	t_env	*temp;

	if (!node)
		return ;
	temp = node->next;
	new->next = temp;
	node->next = new;
}

t_env	*ft_env_new(void)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	env->value = NULL;
	env->next = NULL;
	return (env);
}

t_env	*ft_last_env(t_env *head)
{
	t_env	*cursor;

	cursor = head;
	while (cursor->next != NULL)
		cursor = cursor->next;
	return (cursor);
}

void	free_env(t_infoenv *env)
{
	long long	a;

	a = 0;
	while (a != 1e4)
	{
		if (env->bucket[a] != NULL)
		{
			free(env->bucket[a]->value);
			free(env->bucket[a]);
		}
		a++;
	}
}
