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

char	*is_being_initialized(char *new_env)
{
	return (ft_strchr(new_env, '='));
}

int	lentok(char *str, char tok)
{
	char	*end;

	end = str;
	while (*end && *end != tok)
		end++;
	return (end - str);
}

int	names_are_equal(char *env, char *new_env)
{
	return (cmptok(env, new_env, '='));
}

int	cmptok(char *s1, char *s2, char tok)
{
	int	s1len;
	int	s2len;

	s1len = lentok(s1, '=');
	s2len = lentok(s2, '=');
	if (s1len != s2len)
		return (FALSE);
	while (TRUE)
	{
		if (*s1++ != *s2++)
			return (FALSE);
		if (*s2 == tok || !*s2)
			break ;
		if (*s1 == tok || !*s1)
			break ;
	}
	return (TRUE);

void	get_env_name(char *name, char *env)
{
	char	*equal_sign;

	equal_sign = ft_strchr(env, '=');
	ft_strlcpy(name, env, equal_sign - env + 1);
	return ;
}

void	get_env_content(char *content, char *name, char *env)
{
	char	*found_name;
	char	*equal_sign;

	found_name = ft_strnstr(env, name, STR_LIMIT);
	if (found_name)
	{
		equal_sign = ft_strchr(found_name, '=');
		if (equal_sign && equal_sign[1])
			ft_strlcpy(content, &equal_sign[1], ft_strlen(equal_sign));
		else if (equal_sign && !(equal_sign[1]))
			ft_bzero(content, STR_LIMIT);
		return ;
	}
}