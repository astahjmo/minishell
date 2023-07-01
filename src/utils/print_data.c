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
	printf(RED "number_of_envs:" RESET " %d\n", data->number_of_envs);
	printf(RED "type_stream:" RESET " %d\n", data->type_stream);
	printf(RED "exit_status:" RESET " %d\n", data->exit_status);
	printf(RED "prompt:" RESET " %s\n", data->prompt);
	printf(RED "stream:" RESET " %s\n", data->stream);
	printf(RED "cmds:" RESET " %p\n", data->cmds);
	tmp = data->cmds->head;
	while (tmp)
	{
		printf(RED "    cmds->head:" RESET " %p\n", tmp);
		printf(RED "    cmds->head->token:" RESET " %d\n", tmp->token);
		if (*tmp->str == ' ')
			printf(RED "    cmds->head->str:" RESET " %s\n", "<space>");
		else
			printf(RED "    cmds->head->str:" RESET " %s\n", tmp->str);
		tmp = tmp->next;
	}
	printf(RED "cmds: "RESET"%p\n", tmp);
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
		printf(RED "envs:" RESET " %p\n", data->cmds);
		printf(RED "envp:" RESET " %p\n", data->envp);
		printf(RED "number_of_envs:" RESET "%d\n", data->number_of_envs);
		while (++i < data->number_of_envs)
			printf("env[%d]: %s\n", i, data->env[i]);
	}
}
