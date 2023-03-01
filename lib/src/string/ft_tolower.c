/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*                                                                            */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:47:35 by johmatos          #+#    #+#             */
/*   Updated: 2022/04/27 17:19:49 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_tolower(int c)
{
	c = (unsigned int ) c;
	if (ft_isupper(c))
		return (c | 32);
	else
		return (c);
}
