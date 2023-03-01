/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_to_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:18:51 by johmatos          #+#    #+#             */
/*   Updated: 2022/10/30 15:55:26 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fmt_to_decimal(int nbr)
{
	char	*str;
	int		len;

	str = ft_itoa(nbr);
	len = ft_strlen(str);
	ft_putstr_fd(str, STDOUT_FILENO);
	free(str);
	return (len);
}
