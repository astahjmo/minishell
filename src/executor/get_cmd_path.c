/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 10:52:28 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/07/01 11:13:47 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_t_split(t_split *split, char *path_str);
static char	*test_directory(char *cmd);
static char	*conditional_return(int i, t_get_cmd_path *get);

char	*get_cmd_path(char *cmd)
{
	t_get_cmd_path	get;
	int				i;

	if (!cmd || !*cmd)
		return (NULL);
	i = -1;
	get.slash_address = ft_strchr(cmd, '/');
	if (get.slash_address)
		return (test_directory(cmd));
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

// use fstat or lstat or stat to see if the direcotry exists
static char	*test_directory(char *cmd)
{
	struct stat	buf;

	if (stat(cmd, &buf) == -1)
		getter_data()->exit_status = 127;
	else if (buf.st_mode & S_IFDIR)
		getter_data()->exit_status = 126;
	else if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	return (NULL);
}
