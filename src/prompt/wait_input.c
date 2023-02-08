/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:17:45 by johmatos          #+#    #+#             */
/*   Updated: 2023/02/08 19:40:08 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <readline/readline.h>
#include <stdlib.h>

int	wait_input(int argc, char *argv[], char *envp[])
{
	char	*prompt;
	char	*cmd;

	while (1)
	{
		prompt = get_prompt();
		cmd = readline(prompt);
		free(prompt);
		free(cmd);
	}
	return (1);
}
