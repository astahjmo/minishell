/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 10:52:28 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/07/20 20:17:32 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_t_split(t_split *split, char *path_str);
static char	*conditional_return(int i, t_get_cmd_path *get);
static int	there_is_no_path(char *path);

char	*get_cmd_path(char *cmd)
{
	t_get_cmd_path	get;
	int				i;

	if (!cmd || !*cmd || (there_is_no_path("PATH") && !ft_strchr(cmd, '/')))
		return (NULL);
	i = -1;
	get.slash_address = ft_strchr(cmd, '/');
	if (get.slash_address)
		return (ft_strdup(cmd));
	get.full_possible_size = ft_strlen(cmd) + STR_LIMIT + 1;
	get.full_possible_name = malloc(sizeof(char) * get.full_possible_size);
	get.path_str = get_content_from_name_alone("PATH");
	get.split = split_envp(get.path_str, ':');
	while (++i < get.split->word_count - 1)
	{
		ft_strlcpy(get.full_possible_name, get.split->str_arr[i],
			get.full_possible_size);
		ft_strlcat(get.full_possible_name, "/", get.full_possible_size);
		ft_strlcat(get.full_possible_name, cmd, get.full_possible_size);
		if (access(get.full_possible_name, F_OK | X_OK) == 0)
			break ;
	}
	return (conditional_return(i, &get));
}

static void	free_t_split(t_split *split, char *path_str)
{
	free(path_str);
	free(split->str_arr);
	free(split);
}

static int	there_is_no_path(char *path)
{
	char	*content;

	content = get_content_from_name_alone(path);
	if (!content || !*content)
	{
		free(content);
		return (TRUE);
	}
	free(content);
	return (FALSE);
}

static char	*conditional_return(int i, t_get_cmd_path *get)
{
	int	size;

	size = get->split->word_count;
	free_t_split(get->split, get->path_str);
	if (i == size - 1)
	{
		free(get->full_possible_name);
		return (NULL);
	}
	return (get->full_possible_name);
}
