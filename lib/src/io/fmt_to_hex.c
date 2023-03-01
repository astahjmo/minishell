/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:18:56 by johmatos          #+#    #+#             */
/*   Updated: 2022/10/30 15:52:52 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fmt_to_hex(unsigned int nb, int is_upper)
{
	char	*hex;
	int		len;

	len = 0;
	hex = ft_ithex(nb);
	while (hex && hex[len])
	{
		if (is_upper)
			hex[len] = ft_toupper(hex[len]);
		len++;
	}
	ft_putstr_fd(hex, STDOUT_FILENO);
	free(hex);
	return (len);
}
