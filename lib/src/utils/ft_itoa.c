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

static char	*mstr(char *s, int n);
static int	numlen(int n);
static int	handle_negative(int nbr, char **iter);
static void	build_str(int nbr, char *str, char **iter);

char	*ft_itoa(int nbr)
{
	int		strlen;
	char	*str;
	char	*iter;

	if (nbr == -2147483648)
		return (mstr("-2147483648", 12));
	strlen = numlen(nbr);
	str = (char *)malloc(sizeof(char) * strlen + 1);
	iter = str;
	nbr = handle_negative(nbr, &iter);
	build_str(nbr, str, &iter);
	*iter = '\0';
	return (str);
}

static char	*mstr(char *s, int n)
{
	int		i;
	char	*mstr;

	i = -1;
	mstr = (char *)malloc((n + 1) * sizeof(char));
	while (++i < n)
		*(mstr + i) = *s++;
	mstr[i] = '\0';
	return (mstr);
}

static int	numlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	handle_negative(int nbr, char **iter)
{
	if (nbr < 0)
	{
		*(*iter)++ = '-';
		nbr *= -1;
	}
	return (nbr);
}

static void	build_str(int nbr, char *str, char **iter)
{
	if (nbr > 9)
		build_str(nbr / 10, str, iter);
	*(*iter)++ = (nbr % 10) + '0';
}
