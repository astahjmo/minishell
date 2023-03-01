/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:55:50 by johmatos          #+#    #+#             */
/*   Updated: 2022/05/27 12:26:32 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fc_count(long long lnb)
{
	int	count;

	count = 0;
	while (lnb >= 10)
	{
		count++;
		lnb /= 10;
	}
	return (count);
}

void	ft_putnbr_fd(int nb, int fd)
{
	long long	lnb;
	char		digit[12];
	int			count;

	lnb = (long long) nb;
	count = 0;
	ft_bzero(digit, 12);
	if (lnb < 0)
	{
		digit[0] = '-';
		lnb *= -1;
		count++;
	}
	count = (fc_count(lnb)) + count;
	while (lnb >= 10)
	{
		digit[count] = (char)(lnb % 10) + '0';
		lnb /= 10;
		count--;
	}
	digit[count] = (char)(lnb % 10) + '0';
	ft_putstr_fd(digit, fd);
}
