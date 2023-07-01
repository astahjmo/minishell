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

static void		walk_on_the_list(t_node **lst);
static char		*join_many_strs(t_node **lst);
static t_node	*apply_join_many_strs(t_databus *data);

void	retokenize(void)
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
	int		token;

	new_cmds = NULL;
	aux = data->cmds->head;
	while (aux)
	{
		token = aux->token;
		new_node = create_new_node(join_many_strs(&aux), token);
		lstadd_back(&new_cmds, new_node);
		if (!aux)
			break ;
		aux = aux->next;
	}
	free_cmds(data->cmds);
	return (new_cmds);
}

static char	*join_many_strs(t_node **lst)
{
	char	*result;

	if (!*lst || !(*lst)->str)
		return (NULL);
	result = ft_strdup((*lst)->str);
	if (!(*lst)->next || !(*lst)->next->str || *(*lst)->str == ' ')
		return (result);
	while (1)
	{
		if (!(*lst) || (*lst)->token != T_WORD)
			break ;
		else if ((*lst)->next->token == T_WORD)
		{
			result = strjoinfree_s1(result, (*lst)->next->str);
			walk_on_the_list(lst);
		}
		if (!(*lst)->next || (*lst)->next->token != T_WORD)
			break ;
	}
	return (result);
}

// if (joined) we have to walk two times, else only once
static void	walk_on_the_list(t_node **lst)
{
	if ((*lst)->next)
		*lst = (*lst)->next;
}
