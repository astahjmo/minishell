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

static char	*expand_dollar_env_aux(char *tmp, char *env_name, int i);
static char	*handle_frees(char *tmp, char *new_line, char *line, int dollar);

void	expand_dollar_env_of_all_cmds(void)
{
	t_databus	*data;
	t_node		*list;

	data = getter_data();
	list = data->cmds->head;
	while (list)
	{
		list->str = expand_dollar_env(list->str);
		list = list->next;
	}
}

char	*expand_dollar_env(char *line)
{
	int		i;
	char	*tmp;
	char	*env_name;
	char	*new_line;
	int		have_to_expand;

	i = -1;
	have_to_expand = 0;
	tmp = ft_strdup(line);
	while (tmp[++i])
	{
		if (tmp[i] == '$')
		{
			env_name = get_name(&tmp[i]);
			if (env_name)
			{
				ft_putstr_fd(env_name, 1);
				have_to_expand = 1;
				tmp = expand_dollar_env_aux(tmp, env_name, i);
			}
		}
	}
	new_line = ft_strdup(tmp);
	return (handle_frees(tmp, new_line, line, have_to_expand));
}

static char	*expand_dollar_env_aux(char *tmp, char *env_name, int i)
{
	char	*until_dollar;
	char	*env_content;
	char	*until_env_content_end;
	char	*after_content;
	char	*new_line;

	until_dollar = ft_substr(tmp, 0, i);
	env_content = get_content_from_name_alone(env_name);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd(env_content, 1);
	until_env_content_end = strjoinfree_s1(until_dollar, env_content);
	after_content = ft_strdup(&tmp[i + ft_strlen(env_content) + 1]);
	new_line = strjoinfree_s1(until_env_content_end, after_content);
	free(env_content);
	free(after_content);
	free(tmp);
	return (new_line);
}

static char	*handle_frees(char *tmp, char *new_line, char *line, int has_dollar)
{
	free(tmp);
	if (!has_dollar)
	{
		free(new_line);
		return (line);
	}
	free(line);
	return (new_line);
}
