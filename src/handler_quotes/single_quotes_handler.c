/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_quotes_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loe <loe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:03:27 by lfilipe-          #+#    #+#             */
/*   Updated: 2023/04/21 14:30:25 by loe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>

void	single_quotes_handler(char *line)
{
	int		i;
	int		j;
	int	line_size;
	//char	*string;

	line_size = ft_strlen(line);
	i = 0;
	j = 0;

	while(i < (line_size + 1))
	{
		if (line[i] != '\'')
			line[j++] = line[i];
		i++;
	}
	line[j] = '\0';
	printf("%s\n", line);
}
