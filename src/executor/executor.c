/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:41:22 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/13 17:50:04 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	executor(t_databus *data)
{
	t_tokens		builtin;
	t_fn_built_exec	**exec;
//	int				status;

	exec = get_built_func();
	//status = init_heredoc(data->cmds->head);
//	if (status == 2)
//		return ;
	builtin = is_builtin(data->cmds->head);
	if (builtin != -1)
		exec[builtin](data);
	return ;
}
