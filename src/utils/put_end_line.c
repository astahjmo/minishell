/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_end_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:33:16 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/07/12 14:34:19 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_end_line(char *buf, int fd)
{
	if (buf)
	{
		buf = expand_dollars(buf);
		ft_putendl_fd(buf, fd);
		free(buf);
	}
}
