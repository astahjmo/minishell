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

static void		walk_on_the_list(t_node **lst, int is_joined);
static char		*join_many_strs(t_node **lst, int is_joined);
static t_node	*apply_join_many_strs(t_databus *data);

void	create_new_cmds_list(void)
{
	t_databus	*data;

	data = getter_data();
	data->cmds->head = apply_join_many_strs(data);
}

static t_node	*apply_join_many_strs(t_databus *data)
{
	t_node	*new_cmds;
	t_node	*new_node;
	t_node	*aux;
	int		is_joined;
	int		token;

	is_joined = 0;
	new_cmds = NULL;
	aux = data->cmds->head;
	while (aux)
	{
		token = aux->token;
		new_node = create_new_node(join_many_strs(&aux, is_joined), token);
		lstadd_back(&new_cmds, new_node);
		if (!aux)
			break ;
		aux = aux->next;
	}
	free_cmds(data->cmds);
	return (new_cmds);
}

static char	*join_many_strs(t_node **lst, int is_joined)
{
	char	*result;

	if (!*lst || ((*lst)->token != T_WORD && *(*lst)->str != ' '))
		return (NULL);
	result = ft_strdup((*lst)->str);
	if (!(*lst)->next || *(*lst)->next->str == ' ' || *(*lst)->str == ' ')
	{
		lst = &(*lst)->next;
		return (result);
	}
	while (*lst)
	{
		if (!(*lst)->next || (*lst)->next->token != T_WORD)
		{
			lst = &(*lst)->next;
			break ;
		}
		if ((*lst)->next)
		{
			is_joined = 1;
			result = strjoinfree_s1(result, (*lst)->next->str);
		}
		walk_on_the_list(lst, is_joined);
	}
	return (result);
}

// if (is_joined) we have to walk three times, else only once
static void	walk_on_the_list(t_node **lst, int is_joined)
{
	if (is_joined)
	{
		if ((*lst)->next)
			*lst = (*lst)->next;
		if ((*lst)->next)
			*lst = (*lst)->next;
	}
	*lst = (*lst)->next;
}
