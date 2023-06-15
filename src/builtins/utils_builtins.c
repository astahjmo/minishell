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
		if (*s1 == '=' || *s2 == '=' || !*s2 || !*s1)
			return (TRUE);
		if (*s1 != *s2)
			return (FALSE);
		s1++;
		s2++;
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
// 	printf("names_are_equal tests passed\n");
// }
