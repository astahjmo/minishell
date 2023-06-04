/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:39:48 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/04 05:56:58 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*trim_key(char *key)
{
	int		acc;
	char	*env;

	acc = -1;
	if (*key == '$')
		key++;
	while (key[acc] != ' ' && key[acc] != '\0'
		&& key[acc] != '"' && key[acc] != '\'')
		acc++;
	env = ft_substr(key, 0, acc);
	return (env);
}

char	*get_env(char *env)
{
	t_env			**bucket;
	char			*key;
	long long int	pos;
	char			*value;
	t_env			*environ;

	bucket = get_bucket();
	key = trim_key(env);
	pos = hash_map(key);
	environ = bucket[pos];
	value = environ->value;
	string_eat_at(&value, '=');
	free(key);
	return (value++);
}
