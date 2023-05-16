/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth <astaroth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:03:21 by astaroth          #+#    #+#             */
/*   Updated: 2023/05/16 15:28:09 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_key(char *environ)
{
	char	*key;
	int		len;

	len = 0;
	while (environ[len] != '=')
		len++;
	key = malloc(len + 1 * sizeof(char));
	ft_strlcpy(key, environ, len + 1);
	return (key);
}

static t_env	*init_env(char *str)
{
	t_env		*environ;

	environ = ft_env_new();
	environ->value = str;
	return (environ);
}

static t_env	**get_bucket(void)
{
	static t_env	*bucket[ARR_MAX_BUFF] = {NULL};

	return (bucket);
}

static void	insert_env_on_table(t_infoenv *environ, t_env *env,
			long long int pos)
{
	environ->bucket[pos] = env;
	environ->count++;
}

void	*init_environ(char *envp[], t_infoenv *environ)
{
	int				count;
	t_env			*env;
	char			*key;
	char			*value;
	long long int	pos;

	count = 0;
	environ->bucket = get_bucket();
	while (envp[count] != NULL)
	{
		key = get_key(envp[count]);
		value = ft_strdup(envp[count]);
		env = init_env(value);
		pos = hash_map(key);
		insert_env_on_table(environ, env, pos);
		count++;
		free(key);
	}
	return (NULL);
}