/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:19:32 by johmatos          #+#    #+#             */
/*   Updated: 2022/05/28 12:59:42 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*new;

	len = ft_strlen(src) + 1;
	new = (char *) malloc(len * sizeof(char));
	if (new == NULL)
		return (NULL);
	ft_memmove(new, src, len);
	return (new);
}
