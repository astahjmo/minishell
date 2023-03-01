/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 05:11:48 by johmatos          #+#    #+#             */
/*   Updated: 2022/05/25 21:09:11 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	is_negative;
	int	number;

	is_negative = 1;
	number = 0;
	while ((*str) && (*str >= 0 && *str <= 32) && !(*str == '\e'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			is_negative *= -1;
		}
		str++;
	}
	while ((*str) && (ft_isdigit(*str)))
	{
		number = number * 10 + (*str) - '0';
		str++;
	}
	return (number * is_negative);
}
