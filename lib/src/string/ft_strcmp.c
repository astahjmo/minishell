/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 11:25:03 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/24 17:07:45 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *str1, char *str2)
{
	if (!str1 || !str2)
		return (1);
	while (*str1)
	{
		if (*str1 != *str2)
			return (1);
		str1++;
		str2++;
	}
	if (!*str1 && *str2)
		return (1);
	return (0);
}
