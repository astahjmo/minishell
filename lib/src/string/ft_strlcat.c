/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 03:02:41 by johmatos          #+#    #+#             */
/*   Updated: 2022/05/25 20:56:06 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstt;
	size_t	srcc;

	dstt = 0;
	srcc = 0;
	while (dst[dstt] && dstt < size)
		dstt++;
	while (src[srcc] && (dstt + srcc + 1) < size)
	{
		dst[dstt + srcc] = src[srcc];
		srcc++;
	}
	if (dstt != size)
		dst[dstt + srcc] = 0;
	return (dstt + ft_strlen(src));
}
