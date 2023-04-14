/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_bimatrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:15:30 by johmatos          #+#    #+#             */
/*   Updated: 2023/03/29 22:48:36 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	clear_bimatrix(char **arr)
{
	int	len;

	len = 0;
	while (arr[len] != NULL)
		len++;
	while (len != -1)
		free(arr[len--]);
	free(arr);
}
