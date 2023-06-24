/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:36:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/21 14:36:46 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static t_ull	convert_recursively(const char *a, t_ull toi);
static int		local_is_whitespace(const char c);
static int		is_digit(const char c);

t_ull	ft_atoull(char *str)
{
	while (local_is_whitespace(*str))
		str++;
	return (convert_recursively(str, 0));
}

static int	local_is_whitespace(const char c)
{
	return (c == ' ' || ('\t' <= c && c <= '\r'));
}

static int	is_digit(const char c)
{
	return ((c >= '0' && c <= '9'));
}

static t_ull	convert_recursively(const char *a, t_ull toi)
{
	int	single_digit;

	if (!*a || local_is_whitespace(*a) || !is_digit(*a))
		return (toi);
	single_digit = *a - '0';
	if (toi > (SIZE_MAX - single_digit) / 10)
		return (SIZE_MAX);
	toi = toi * 10 + single_digit;
	return (convert_recursively(a + 1, toi));
}
