/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ubase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:20:09 by johmatos          #+#    #+#             */
/*   Updated: 2022/10/30 15:55:53 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fill_array(u_long num, char *arr,
		unsigned long size, unsigned long base)
{
	while (num >= base)
	{
		arr[size] = MASK_HEX[(num % base)];
		num /= base;
		size--;
	}
	arr[size] = MASK_HEX[(num % base)];
}

char	*ft_ubase(unsigned long nb, unsigned long base)
{
	unsigned long	aux;
	size_t			int_size;
	char			*str;

	aux = nb;
	int_size = 0;
	while (aux >= base)
	{
		aux /= base;
		int_size++;
	}
	int_size += 2;
	str = malloc((sizeof(char) * int_size));
	str[int_size -1] = '\0';
	ft_fill_array(nb, str, (int_size - 2), base);
	return (str);
}
