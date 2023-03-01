/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_to_udecimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:19:25 by johmatos          #+#    #+#             */
/*   Updated: 2022/10/30 15:53:12 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fmt_to_udecimal(unsigned int n)
{
	char	*str;
	int		len;

	str = ft_ubase(n, 10);
	len = ft_strlen(str);
	ft_putstr_fd(str, STDOUT_FILENO);
	free (str);
	return (len);
}
