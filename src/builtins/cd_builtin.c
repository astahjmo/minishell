/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 08:42:30 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/25 11:06:30 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	pwd_idx(void);
static int	oldpwd_idx(void);
static void	update_pwd_and_oldpwd(char *cwd);
static int	path_is_valid(void);

void	cd_builtin(t_node *current)
{
	char	*path;
	char	cwd[STR_LIMIT];

	path = NULL;
	if (current->next)
		path = current->next->str;
	else
		path = get_content_from_name_alone("HOME");
	getter_data()->exit_status = chdir(path);
	if (-1 == path_is_valid())
		return ;
	getcwd(cwd, STR_LIMIT);
	update_pwd_and_oldpwd(cwd);
	ft_safe_free((void **)&path);
}

static int	path_is_valid(void)
{
	int	exit_status;

	exit_status = getter_data()->exit_status;
	if (exit_status == -1)
		printf("%s\n", "Error, you need a correct parameter");
	return (exit_status);
}

static void	update_pwd_and_oldpwd(char *cwd)
{
	t_databus	*data;

	data = getter_data();
	ft_strlcpy(data->env[oldpwd_idx()], data->env[pwd_idx()], STR_LIMIT);
	ft_strlcpy(data->env[pwd_idx()], cwd, STR_LIMIT);
}

static int	pwd_idx(void)
{
	t_databus	*data;
	int			i;

	i = 0;
	data = getter_data();
	while (i < data->number_of_envs)
	{
		if (!ft_strncmp(data->env[i], "PWD=", 4))
			return (i);
		i++;
	}
	overwrite_env(data, "PWD=");
	return (data->number_of_envs - 1);
}

static int	oldpwd_idx(void)
{
	t_databus	*data;
	int			i;

	i = 0;
	data = getter_data();
	while (i < data->number_of_envs)
	{
		if (!ft_strncmp(data->env[i], "OLDPWD=", 7))
			return (i);
		i++;
	}
	overwrite_env(data, "OLDPWD=");
	return (data->number_of_envs - 1);
}
