/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:19:33 by johmatos          #+#    #+#             */
/*   Updated: 2022/10/30 15:53:18 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *s, ...)
{
	va_list		ap;
	int			len;

	if (!s)
		return (0);
	va_start(ap, s);
	len = fparser(s, ap);
	va_end(ap);
	return (len);
}
