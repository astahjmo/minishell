/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_many_strs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:49:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/27 09:57:00 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_many_strs(t_node **head)
{
	char	*result;

	result = ft_strdup("");
	while (*(*head)->str != ' ')
	{
		result = strjoinfree_s1(result, (*head)->str);
		head = &(*head)->next;
	}
	return (result);
}
