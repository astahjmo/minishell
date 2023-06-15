/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:06:28 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/15 10:09:55 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

inline int	is_initialized_to_zero(char *str)
{
	int	i;

	i = 0;
	while (i < STR_LIMIT)
	{
		if (str[i] != '\0')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

inline int	is_being_initialized(char *new_env)
{
	if (ft_strchr(new_env, '='))
		return (TRUE);
	return (FALSE);
}

int	names_are_equal(char *s1, char *s2)
{
	while (TRUE)
	{
		if (*s1 == '=' || !*s2 || !*s1)
			return (TRUE);
		if (*s1 != *s2)
			return (FALSE);
		s1++;
		s2++;
	}
}

void	get_env_name(t_databus *data, char *env, char *name)
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
			ft_strlcpy(env, found_name, equal_sign - found_name + 1);
			return ;
		}
		i++;
	}
}

void	get_env_content(char *content, char *name, char *env)
{
	char	*found_name;
	char	*equal_sign;

	found_name = ft_strnstr(env, name, STR_LIMIT);
	if (found_name)
	{
		equal_sign = ft_strchr(found_name, '=');
		if (equal_sign && *(equal_sign + 1))
			ft_strlcpy(content, equal_sign + 1, ft_strlen(equal_sign));
		else if (equal_sign && !*(equal_sign + 1))
			ft_bzero(content, STR_LIMIT);
		return ;
	}
}

// tests for names_are_equal
// #include <assert.h>
//
// int	main(void)
// {
// 	assert(names_are_equal("a", "a") == TRUE);
// 	assert(names_are_equal("a", "b") == FALSE);
// 	assert(names_are_equal("a", "a=") == TRUE);
// 	assert(names_are_equal("a", "a=b") == TRUE);
// 	assert(names_are_equal("a=", "a") == TRUE);
// 	assert(names_are_equal("a=", "a=") == TRUE);
// 	assert(names_are_equal("a=b", "a") == TRUE);
// 	assert(names_are_equal("a=b", "a=") == TRUE);
// 	assert(names_are_equal("a=b", "a=b") == TRUE);
// 	assert(names_are_equal("a=", "a==") == TRUE);
// 	assert(names_are_equal("a==", "a=") == TRUE);
// 	assert(names_are_equal("a==", "a==") == TRUE);
// 	assert(names_are_equal("a===", "a==") == TRUE);
// 	assert(names_are_equal("as", "a=") == FALSE);
// 	printf("names_are_equal tests passed\n");
// }
