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

static int	set_color(char *color, char result[1024]);
static void	expand_format_str(t_strings *strs, int *len, int *i, char *result);

char	*miniprintf(char *format, char *color, t_strings strs)
{
	int			i;
	int			param_len;
	int			format_idx;
	static char	result[1024];

	param_len = 0;
	format_idx = 0;
	i = set_color(color, result);
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
	ft_strlcat(result, RESET, ft_strlen(result));
	return (result);
}

static int	set_color(char *color, char result[1024])
{
	int	color_len;
	int	i;

	color_len = 0;
	i = 0;
	if (color)
	{
		color_len = ft_strlen(color);
		ft_strlcpy(result, color, 1023);
		i += color_len;
	}
	return (i);
}

static void	expand_format_str(t_strings *strs, int *len, int *i, char *result)
{
	*len = ft_strlen(strs->next);
	ft_strlcat(result, strs->next, *len);
	(*i) += *len;
	strs->next = strs->str2;
	strs->str2 = strs->str3;
	strs->str3 = NULL;
}
