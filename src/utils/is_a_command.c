/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:20:19 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/07/12 12:22:18 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_a_command(void)
{
	char	*address;

	address = get_cmd_path(getter_data()->cmds->head->str);
	if (address)
	{
		free(address);
		return (FALSE);
	}
	return (TRUE);
}
