/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recipeOperator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth <astaroth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:10:05 by astaroth          #+#    #+#             */
/*   Updated: 2023/05/15 12:18:05 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_operator_recipe(t_tokens token)
{
	static int	transiction[3] = {1, -1, -1};

	return (transiction[token]);
}
