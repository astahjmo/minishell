/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos < johmatos@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 03:20:41 by johmatos          #+#    #+#             */
/*   Updated: 2022/05/27 03:56:36 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				count;
	unsigned char		*d;
	const unsigned char	*s;

	if (!(dest || src))
		return (NULL);
	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	count = -1;
	while (++count < n)
		d[count] = s[count];
	return (dest);
}
