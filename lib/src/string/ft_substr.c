/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:45:03 by johmatos          #+#    #+#             */
/*   Updated: 2022/05/25 22:25:17 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	size_t		str_len;

	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
		str_len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (str_len > len)
		str_len = len;
	substr = (char *)ft_calloc(sizeof(char), str_len + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, (s + start), (str_len + 1));
	return (substr);
}
