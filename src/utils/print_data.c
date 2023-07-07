/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:33:01 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/28 17:35:10 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_envs(void);

void	print_data(int env)
{
	t_databus	*data;
	t_node		*tmp;

	data = getter_data();
	ft_printf(RED "number_of_envs:" RESET " %d\n", data->number_of_envs);
	ft_printf(RED "type_stream:" RESET " %d\n", data->type_stream);
	ft_printf(RED "exit_status:" RESET " %d\n", data->exit_status);
	ft_printf(RED "prompt:" RESET " %s\n", data->prompt);
	ft_printf(RED "stream:" RESET " %s\n", data->stream);
	ft_printf(RED "cmds:" RESET " %p\n", data->cmds);
	tmp = data->cmds->head;
	while (tmp)
	{
		ft_printf(RED "    cmds->head:" RESET " %p\n", tmp);
		ft_printf(RED "    cmds->head->token:" RESET " %d\n", tmp->token);
		if (*tmp->str == ' ')
			ft_printf(RED "    cmds->head->str:" RESET " \"%s\"\n", "<space>");
		else
			ft_printf(RED "    cmds->head->str:" RESET " \"%s\"\n", tmp->str);
		tmp = tmp->next;
	}
	ft_printf(RED "cmds: "RESET"%p\n", tmp);
	if (env)
		print_envs();
}

void	print_envs(void)
{
	int			i;
	t_databus	*data;

	i = -1;
	data = getter_data();
	{
		ft_printf(RED "envs:" RESET " %p\n", data->cmds);
		ft_printf(RED "envp:" RESET " %p\n", data->envp);
		ft_printf(RED "number_of_envs:" RESET "%d\n", data->number_of_envs);
		while (++i < data->number_of_envs)
			ft_printf("env[%d]: %s\n", i, data->env[i]);
	}
}
