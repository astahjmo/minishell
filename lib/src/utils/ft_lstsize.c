/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:57:20 by johmatos          #+#    #+#             */
/*   Updated: 2022/12/06 15:12:59 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int ft_lstsize(t_node *node)
{
	int	i;
	
	i = 1;
	while (node->next != NULL)
	{
		i++;
		node = node->next;
	}
	return (i);
}
