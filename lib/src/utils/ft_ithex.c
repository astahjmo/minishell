/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ithex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:20:18 by johmatos          #+#    #+#             */
/*   Updated: 2022/10/30 15:55:38 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fill_array(u_long num, char *arr, size_t size)
{
	while (num >= 16)
	{
		arr[size] = MASK_HEX[(num % 16)];
		num /= 16;
		size--;
	}
	arr[size] = MASK_HEX[(num % 16)];
}

char	*ft_ithex(unsigned int nb)
{
	unsigned int	aux;
	size_t			int_size;
	char			*str;

	aux = (unsigned int)nb;
	int_size = 0;
	while (aux >= 16)
	{
		aux /= 16;
		int_size++;
	}
	int_size += 2;
	str = malloc((sizeof(char) * int_size));
	str[int_size - 1] = '\0';
	ft_fill_array(nb, str, (int_size - 2));
	return (str);
}
