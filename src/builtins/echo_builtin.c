/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:02:26 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/07/14 14:52:25 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_dash_n(char *str);

void	echo_builtin(t_node *current)
{
	t_bool	n_flag;
	int		cmd_io;

	n_flag = 0;
	cmd_io = getter_data()->cmds->idx;
	if (current->next)
		current = current->next;
	while (current && current->next && is_dash_n(current->next->str))
	{
		n_flag = 1;
		current = current->next->next;
	}
	while (current && current->next)
	{
		current = current->next;
		if (current->str)
			ft_putstr_fd(current->str, command_hook(cmd_io)->output);
	}
	if (!n_flag)
		ft_putstr_fd("\n", command_hook(cmd_io)->output);
	getter_data()->exit_status = 0;
}

static int	is_dash_n(char *str)
{
	t_bool	dash_n;
	int		len;
	int		i;

	len = ft_strlen(str);
	dash_n = FALSE;
	i = 0;
	if (str[i] == '-' && str[++i] == 'n')
		dash_n = TRUE;
	while (i < len)
	{
		if (str[i] != 'n')
			return (FALSE);
		i++;
	}
	return (dash_n);
}
