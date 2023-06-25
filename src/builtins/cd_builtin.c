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

static int	path_is_valid(int chdir_return);
static void	update_pwd_and_oldpwd(char *cwd);

void	cd_builtin(t_node *current)
{
	char	*home;
	char	**path_address;
	char	cwd[STR_LIMIT];

	if (current->next)
		path_address = &current->next->str;
	else
	{
		home = get_content_from_name_alone("HOME");
		path_address = &home;
	}
	if (-1 == path_is_valid(chdir(*path_address)))
		return ;
	getcwd(cwd, STR_LIMIT);
	update_pwd_and_oldpwd(cwd);
	ft_safe_free(path_address);
}

static int	path_is_valid(int chdir_return)
{
	if (chdir_return == -1)
	{
		ft_putstr_fd("No such file or directory\n", 2);
		getter_data()->exit_status = 1;
	}
	return (chdir_return);
}

static void	update_pwd_and_oldpwd(char *cwd)
{
	t_databus	*data;
	int			pwdlen;

	data = getter_data();
	pwdlen = ft_strlen(data->env[pwd_idx()]);
	ft_strlcpy(data->env[oldpwd_idx()] + 7, data->env[pwd_idx()] + 4, pwdlen);
	ft_strlcpy(data->env[pwd_idx()] + 4, cwd, ft_strlen(cwd) + 1);
}
