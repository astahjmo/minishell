/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_many_strs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:49:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/28 16:49:27 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*join_many_strs(t_node **lst)
{
	char	*result;

	if (!lst || !*lst || ((*lst)->token != T_WORD && (*lst)->token != T_SPACE))
		return (NULL);
	if ((*lst)->next && (*lst)->next->token == T_SPACE)
	{
		lst = &(*lst)->next;
		return (ft_strdup(" "));
	}
	result = ft_strdup((*lst)->str);
	while (*lst)
	{
		if (!(*lst)->next || (*lst)->next->token != T_WORD)
		{
			lst = &(*lst)->next;
			break ;
		}
		if ((*lst)->next)
			result = strjoinfree_s1(result, (*lst)->next->str);
		lst = &(*lst)->next;
	}
	return (result);
}

static t_node	*apply_join_many_strs(t_databus *data)
{
	t_node	*result;
	t_node	*new_node;
	t_node	*aux;

	result = NULL;
	aux = data->cmds->head->next->next;
	while (aux)
	{
		new_node = lstnew(join_many_strs(&aux));
		if (!new_node)
			return (NULL);
		lstadd_back(&result, new_node);
		aux = aux->next;
	}
	lstfree(&data->cmds->head);
	return (result);
}

void	create_new_cmds_list(void)
{
	t_databus	*data;

	data = getter_data();
	data->cmds->head = apply_join_many_strs(data);
}
