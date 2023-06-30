/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:58:10 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/26 22:14:51 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*expand_dollar_env(char *tmp, char *env_name, int i);
static char	*expand_dollar_question(char *tmp, int i);

void	handle_expansions(void)
{
	t_databus	*data;
	t_node		*list;

	data = getter_data();
	list = data->cmds->head;
	while (list)
	{
		if (list->str && *list->str != '\'')
			list->str = expand_dollars(list->str);
		list = list->next;
	}
}

char	*expand_dollars(char *line)
{
	int		i;
	char	*tmp;
	char	*env_name;
	char	*new_line;
	int		have_to_expand;

	i = -1;
	have_to_expand = 0;
	tmp = ft_strdup(line);
	while (*tmp && tmp[++i])
	{
		if (tmp[i] == '$')
		{
			env_name = get_name(&tmp[i]);
			if (env_name)
			{
				have_to_expand = 1;
				tmp = expand_dollar_env(tmp, env_name, i);
			}
			else if (tmp[i + 1] == '?')
				tmp = expand_dollar_question(tmp, i);
		}
	}
	new_line = ft_strdup(tmp);
	return (handle_frees(tmp, new_line, line, have_to_expand));
}

static char	*expand_dollar_env(char *tmp, char *env_name, int i)
{
	char	*until_dollar;
	char	*env_content;
	char	*until_env_content_end;
	char	*after_content;
	char	*new_line;

	until_dollar = ft_substr(tmp, 0, i);
	env_content = get_content_from_name_alone(env_name);
	until_env_content_end = strjoinfree_s1(until_dollar, env_content);
	after_content = ft_strdup(&tmp[i + ft_strlen(env_name) + 1]);
	new_line = strjoinfree_s1(until_env_content_end, after_content);
	free(env_content);
	free(after_content);
	free(tmp);
	free(env_name);
	return (new_line);
}

static char	*expand_dollar_question(char *tmp, int i)
{
	char	*until_dollar;
	char	*exit_status;
	char	*until_exit_status_end;
	char	*after_question_mark;
	char	*new_line;

	until_dollar = ft_substr(tmp, 0, i);
	exit_status = ft_itoa(getter_data()->exit_status);
	until_exit_status_end = strjoinfree_s1(until_dollar, exit_status);
	after_question_mark = ft_strdup(&tmp[i + ft_strlen(exit_status) + 1]);
	new_line = strjoinfree_s1(until_exit_status_end, after_question_mark);
	free(exit_status);
	free(after_question_mark);
	free(tmp);
	return (new_line);
}
