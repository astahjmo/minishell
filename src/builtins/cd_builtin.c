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

static int	path_is_invalid(char **path_address);
static void	update_pwd_and_oldpwd(char *cwd);
static int	cd_has_too_many_args(void);

void	cd_builtin(t_node *current)
{
	char	*home;
	char	**path_address;
	char	cwd[STR_LIMIT];

	path_address = &next_node_with_this_token(current->next, T_WORD)->str;
	if (!next_node_with_this_token(current->next, T_WORD))
	{
		home = get_content_from_name_alone("HOME");
		path_address = &home;
	}
	if (cd_has_too_many_args())
		return ;
	if (path_is_invalid(path_address))
		return ;
	getcwd(cwd, STR_LIMIT);
	update_pwd_and_oldpwd(cwd);
	ft_safe_free(path_address);
	getter_data()->exit_status = 0;
}

static int	cd_has_too_many_args(void)
{
	if (has_too_many_args())
	{
		ft_putstr_fd("minishell: cd:", 1);
		ft_putstr_fd(" too many arguments\n", 2);
		getter_data()->exit_status = 1;
		return (TRUE);
	}
	return (FALSE);
}

static int	path_is_invalid(char **path_address)
{
	int	chdir_return;

	if (**path_address == '\0')
	{
		ft_putstr_fd("minishell: cd:", 1);
		ft_putstr_fd(" HOME not set\n", 2);
		getter_data()->exit_status = 1;
		ft_safe_free(path_address);
		return (TRUE);
	}
	chdir_return = chdir(*path_address);
	if (chdir_return == -1)
	{
		ft_putstr_fd("minishell: cd:", 1);
		ft_putstr_fd(" No such file or directory\n", 2);
		getter_data()->exit_status = 1;
		return (TRUE);
	}
	return (FALSE);
}

static void	update_pwd_and_oldpwd(char *cwd)
{
	t_databus	*d;
	int			len;

	d = getter_data();
	len = ft_strlen(d->env[get_pwd_idx()]);
	ft_strlcpy(d->env[get_oldpwd_idx()] + 7, d->env[get_pwd_idx()] + 4, len);
	ft_strlcpy(d->env[get_pwd_idx()] + 4, cwd, ft_strlen(cwd) + 1);
}
