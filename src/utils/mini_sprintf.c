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

static void	expand_format_str(t_strings *strs, int *len, int *i, char *result);

char	*mini_sprintf(char *format, t_strings strs)
{
	int			i;
	int			param_len;
	int			format_idx;
	char		result[STR_LIMIT] = {0};

	i = 0;
	param_len = 0;
	format_idx = 0;
	while (format[format_idx])
	{
		if (format[format_idx] == '%' && format[format_idx + 1] == 's')
		{
			if (strs.next)
				expand_format_str(&strs, &param_len, &i, result);
			format_idx += 2;
		}
		else
			result[i++] = format[format_idx++];
	}
	return (ft_strdup(result));
}

static void	expand_format_str(t_strings *strs, int *len, int *i, char *result)
{
	*len = ft_strlen(strs->next);
	strncat(result, strs->next, *len);
	(*i) += *len;
	strs->next = strs->str2;
	strs->str2 = strs->str3;
	strs->str3 = NULL;
}
