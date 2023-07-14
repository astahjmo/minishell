/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtins_03.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 09:22:59 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/07/14 09:23:11 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_ext_code_after_builtin(t_node *current)
{
	(void)current;
	getter_data()->exit_status = 0;
}

void	set_ext_code_after_export(int valid)
{
	getter_data()->exit_status = 0;
	if (FALSE == valid)
		getter_data()->exit_status = 1;
}
