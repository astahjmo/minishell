/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:25:07 by johmatos          #+#    #+#             */
/*   Updated: 2022/10/30 13:17:38 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int find)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count])
	{
		if (str[count] == find)
			return (&str[count]);
		count++;
	}
	return (NULL);
}
