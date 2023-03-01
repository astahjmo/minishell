/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_to_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:19:00 by johmatos          #+#    #+#             */
/*   Updated: 2022/10/30 15:55:29 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fmt_to_pointer(void *pointer)
{
	u_long	aux_p;
	size_t	len;
	char	*str;

	aux_p = (unsigned long) pointer;
	if (!(aux_p))
	{
		ft_putstr_fd("(nil)", STDOUT_FILENO);
		return (5);
	}
	str = ft_ubase(aux_p, 16);
	len = ft_strlen(str);
	ft_putstr_fd("0x", STDOUT_FILENO);
	ft_putstr_fd(str, STDOUT_FILENO);
	free(str);
	return (len + 2);
}
