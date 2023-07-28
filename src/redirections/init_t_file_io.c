/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_file_io.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:34:44 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/07/12 19:50:37 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_io	*getter_t_ios(void)
{
	static t_io	io[MAX_FD] = {0};

	return (io);
}

int	*getter_heredoc_tmp(void)
{
	static int	heredoc[MAX_FD] = {0};

	return (heredoc);
}

int	*getter_input(void)
{
	static int	 input_r[MAX_FD] = {0};
	
	return (input_r);
}

int	*getter_output(void)
{
	static int	output_r[MAX_FD] = {0};
	
	return (output_r);
}
