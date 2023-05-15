/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_recipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth <astaroth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:12:12 by astaroth          #+#    #+#             */
/*   Updated: 2023/05/15 14:36:37 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_recipes	**init_recipes(void)
{
	static t_recipes	*recipes[4] = {
		&get_word_recipe,
		&get_operator_recipe,
		NULL
	};

	return (recipes);
}
