/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 06:51:53 by johmatos          #+#    #+#             */
/*   Updated: 2023/05/20 07:17:38 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*trim_key(char *key)
{
	int		acc;
	char	*env;

	acc = 0;
	while(key[acc] != ' ' && key[acc] != '\0')
		acc++;
	env = ft_substr(key, 0 , acc);
	return (env);
}

// start -> $PATH
//				  ^
//				 end