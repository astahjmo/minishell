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

char *is_being_initialized(char *new_env)
{
	return(ft_strchr(new_env, '='));
}

int lentok(char *str, char tok) {
    char *end;
    end = str;
    while (*end && *end != tok)
        end++;
    return (end - str);
}

int names_are_equal(char *env, char *new_env)
{
	return (cmptok(env, new_env, '='));
}

int cmptok(char *s1, char *s2, char tok) {
    int s1len;
    int s2len;

    s1len = lentok(s1, '=');
    s2len = lentok(s2, '=');
    if (s1len != s2len)
        return (FALSE);
    while (TRUE) {
        if (*s1++ != *s2++)
            return (FALSE);
        if (*s2 == tok || !*s2)
            break;
        if (*s1 == tok || !*s1)
            break;
    }
    return (TRUE);
}
