/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:41:22 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/21 19:41:46 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	executor(t_databus *data)
{
	t_tokens		builtin_idx;
	t_fn_built_exec	**exec;
	unsigned int	status;

	exec = get_built_func();
	status = init_heredoc(data->cmds->head);
	if (WEXITSTATUS(status) == 129)
		return ;
	builtin_idx = is_builtin(data);
	if (builtin_idx != -1)
		exec[builtin_idx](data->cmds->head);
	return ;
}
