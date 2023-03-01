/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:22:09 by johmatos          #+#    #+#             */
/*   Updated: 2022/05/24 20:05:18 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fill_array(long num, char *arr, int size)
{
	if (num < 0)
	{
		arr[0] = '-';
		num = -num;
	}
	while (num >= 10)
	{
		arr[size] = (num % 10) + '0';
		num /= 10;
		size--;
	}
	arr[size] = (num % 10) + '0';
}

char	*ft_itoa(int n)
{
	char	*arr;
	long	num;
	int		is_negative;
	int		int_size;

	int_size = 1;
	is_negative = 0;
	num = n;
	if (n < 0)
		is_negative = 1;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		int_size++;
	}
	arr = malloc(sizeof(char) * (int_size + is_negative) + 1);
	if (arr == NULL)
		return (NULL);
	ft_fill_array(num, arr, (int_size + is_negative) - 1);
	arr[int_size + is_negative] = '\0';
	return (arr);
}
