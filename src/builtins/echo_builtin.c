/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:02:26 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/18 15:02:39 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_builtin(t_node *current)
{
	int	n_flag;

	n_flag = 0;
	if (current->next && !ft_strncmp(current->next->str, "-n", 2))
	{
		n_flag = 1;
		current = current->next;
	}
	while (current->next)
	{
		current = current->next;
		ft_putstr_fd(current->str, 1);
		if (current->next && current->str[0])
			write(1, " ", 1);
	}
	if (!n_flag)
		write(1, "\n", 1);
}
