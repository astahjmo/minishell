/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_expansions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 05:32:09 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/22 16:44:29 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*expand_dollar_question_aux(char *line, int i);

// substitues each $? in a string by an ft_itoa(data->exit_status);
// and returns a dup of the new string all $? substituted
void	expand_dollar_question_of_all_cmds(void)
{
	t_databus	*data;
	t_node		*list;

	data = getter_data();
	list = data->cmds->head;
	while (list)
	{
		list->str = expand_dollar_question(list->str);
		list = list->next;
	}
}

char	*expand_dollar_question(char *line)
{
	int		i;
	char	*tmp;
	char	*new_line;
	int		has_dollar_sign;

	i = 0;
	has_dollar_sign = 0;
	tmp = ft_strdup(line);
	while (tmp[i])
	{
		if (tmp[i] == '$' && tmp[i + 1] == '?')
		{
			has_dollar_sign = 1;
			tmp = expand_dollar_question_aux(tmp, i);
		}
		i++;
	}
	new_line = ft_strdup(tmp);
	free(tmp);
	if (!has_dollar_sign)
		return (free(new_line), line);
	free(line);
	return (new_line);
}

static char	*expand_dollar_question_aux(char *tmp, int i)
{
	char	*until_dollar;
	char	*exit_status;
	char	*until_exit_status_end;
	char	*after_question_mark;
	char	*new_line;

	until_dollar = ft_substr(tmp, 0, i);
	exit_status = ft_itoa(getter_data()->exit_status);
	until_exit_status_end = ft_strjoinfree_s1(until_dollar, exit_status);
	after_question_mark = ft_strdup(&tmp[i + ft_strlen(exit_status) + 1]);
	new_line = ft_strjoinfree_s1(until_exit_status_end, after_question_mark);
	free(exit_status);
	free(after_question_mark);
	free(tmp);
	return (new_line);
}
