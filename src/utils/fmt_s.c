/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 20:07:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/07/09 20:07:51 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	expand_format_str(t_strings *strs, char *result);

char	*fmt_s(char *format, char *s1, char *s2, char *s3)
{
	int			i;
	int			format_idx;
	char		result[STR_LIMIT];
	t_strings	strs;

	i = 0;
	format_idx = 0;
	ft_bzero(result, STR_LIMIT);
	strs = (t_strings){.next = s1, .str2 = s2, .str3 = s3};
	while (format[format_idx])
	{
		if (format[format_idx] == '%' && format[format_idx + 1] == 's')
		{
			if (strs.next)
				expand_format_str(&strs, result);
			format_idx += 2;
			i = ft_strlen(result);
		}
		else
			result[i++] = format[format_idx++];
	}
	return (ft_strdup(result));
}

static void	expand_format_str(t_strings *strs, char *result)
{
	ft_strlcat(result, strs->next, STR_LIMIT);
	strs->next = strs->str2;
	strs->str2 = strs->str3;
	strs->str3 = NULL;
}
