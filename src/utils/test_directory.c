/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_directory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:17:06 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/07/20 20:17:30 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	is_dir(char *path);
static t_bool	is_permission_denied(char *cmd);

char	*test_directory(char *cmd)
{
	struct stat	buf;

	if (cmd && stat(cmd, &buf) == -1)
		getter_data()->exit_status = 127;
	if (is_dir(cmd))
		return (NULL);
	else if (is_permission_denied(cmd))
		return (NULL);
	if (cmd && access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	getter_data()->exit_status = 127;
	return (NULL);
}

static t_bool	is_dir(char *path)
{
	struct stat	file_stat;

	if (!path)
		return (0);
	file_stat.st_mode = 0;
	stat(path, &file_stat);
	if (S_ISDIR(file_stat.st_mode))
		getter_data()->exit_status = 126;
	return (S_ISDIR(file_stat.st_mode));
}

static t_bool	is_permission_denied(char *cmd)
{
	struct stat	stat_res;
	mode_t		bits;

	if (cmd && stat(cmd, &stat_res) >= 0)
	{
		bits = stat_res.st_mode;
		if ((bits & S_IRUSR) == 0)
		{
			getter_data()->exit_status = 126;
			return (TRUE);
		}
		return (FALSE);
	}
	else
	{
		if (errno == EACCES)
		{
			getter_data()->exit_status = 126;
			return (TRUE);
		}
		return (FALSE);
	}
}
