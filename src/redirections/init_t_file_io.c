/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_file_io.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:34:44 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/07/12 18:37:52 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_file_io	*getter_t_file_io(void)
{
	static t_file_io	io[MAX_FD];

	ft_bzero(&io, MAX_FD);
	return (io);
}
