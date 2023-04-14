/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:07:39 by johmatos          #+#    #+#             */
/*   Updated: 2023/03/29 22:35:05 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_concat_str(char *pattern, char *str, int offset)
{
	int		slen;
	char	*string;
	int		idx;
	int		idxx;

	slen = ft_strlen(str);
	string = NULL;
	idx = -1;
	idxx = -1;
	string = ft_calloc(ft_strlen(pattern) + slen * sizeof(char), sizeof(char));
	while (++idx != offset)
		string[idx] = pattern[idx];
	while (++idxx != slen)
		string[idx++] = str[idxx];
	offset++;
	while (pattern[++offset] != '\0')
		string[idx++] = pattern[offset];
	free(pattern);
	return (string);
}

static char	*handler_string(char *pattern, va_list str)
{
	int		offset;

	offset = 0;
	while (pattern[offset] != '\0')
	{
		if (pattern[offset] == '%')
			pattern = ft_concat_str(pattern, va_arg(str, char *), offset);
		offset++;
	}
	return (pattern);
}

char	*ft_interpol(char *pattern, ...)
{
	va_list		ap;
	char		*string;

	pattern = ft_strdup(pattern);
	string = NULL;
	if (!pattern)
		return (NULL);
	va_start(ap, pattern);
	string = handler_string(pattern, ap);
	va_end(ap);
	return (string);
}
