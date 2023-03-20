/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_bimatrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:15:30 by johmatos          #+#    #+#             */
/*   Updated: 2023/03/17 22:17:07 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	clear_bimatrix(char **arr)
{
	int	len;

	while (arr[len] != NULL)
		len++;
	while (len != -1)
		free(arr[len--]);
	free(arr);
}
