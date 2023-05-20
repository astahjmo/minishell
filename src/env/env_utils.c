/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:39:48 by johmatos          #+#    #+#             */
/*   Updated: 2023/05/20 06:33:32 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env(char *env)
{
	t_env			**bucket;
	long long int	pos;
	char			*value;
	t_env			*environ;

	bucket = get_bucket();
	pos = hash_map(env);
	environ = bucket[pos];
	value = environ->value;
	string_eat_at(&value, '=');
	return (value++);
}