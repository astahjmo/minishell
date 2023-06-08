/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:03:21 by astaroth          #+#    #+#             */
/*   Updated: 2023/05/20 06:28:16 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline void	set_key_and_value(char *environ, char key[NAME], char value[VALUE])
{
	int	len;

	len = 0;
	while (environ[len] != '=')
		len++;
	ft_strlcpy(key, environ, ++len);
	ft_strlcpy(value, &environ[len], ft_strlen(&environ[len]) + 1);
}

static t_env	*init_env(char value[ENVARVALUE_LENGTH])
{
	t_env		*environ;

	environ = ft_env_new();
	ft_strlcpy(environ->value, value, ft_strlen(value) + 1);
	return (environ);
}

t_env	**get_bucket(void)
{
	static t_env	*bucket[ARR_MAX_BUFF] = {NULL};

	return (bucket);
}

static inline void	insert_env_on_table(t_infoenv *environ, t_env *env, lli pos)
{
	environ->bucket[pos] = env;
	environ->count++;
}

void	*init_environ(char *envp[], t_infoenv *environ)
{
	int				count;
	t_env			*env;
	char			key[ENVARNAME_LENGTH];
	char			value[ENVARVALUE_LENGTH];
	long long int	pos;

	count = 0;
	environ->bucket = get_bucket();
	while (envp[count] != NULL)
	{
		set_key_and_value(envp[count], key, value);
		env = init_env(value);
		pos = hash_map(key);
		insert_env_on_table(environ, env, pos);
		count++;
	}
	return (NULL);
}
