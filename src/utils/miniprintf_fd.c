/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniprintf_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:02:01 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/07/08 16:03:15 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*mini_printf(char *color, char *format, (t_strings)strings)
{
	char		*reset_color;
	static char	result[1024];
	size_t		result_idx;
	size_t		format_idx;
	size_t		color_len;
	size_t		param_len;
	size_t		reset_color_len;

	result_idx = 0;
	format_idx = 0;
	if (color)
	{
		color_len = strlen(color);
		strncpy(result + result_idx, color, sizeof(result) - result_idx - 1);
		result_idx += color_len;
	}
	while (format[format_idx])
	{
		if (format[format_idx] == '%' && format[format_idx + 1] == 's')
		{
			if (param1)
			{
				param_len = strlen(param1);
				strncpy(result + result_idx, param1, sizeof(result) - result_idx
						- 1);
				result_idx += param_len;
				param1 = param2;
				param2 = param3;
				param3 = NULL;
			}
			format_idx += 2;
		}
		else
		{
			result[result_idx++] = format[format_idx++];
		}
	}
	if (color != NULL)
	{
		reset_color = "\033[0m";
		reset_color_len = strlen(reset_color);
		strncpy(result + result_idx, reset_color, sizeof(result) - result_idx
				- 1);
		result_idx += reset_color_len;
	}
	result[result_idx] = '\0';
	return (result);
}

int	main(void)
{
	char	*param1;
	char	*param2;
	char	*param3;
	char	*result;

	param1 = "value1";
	param2 = "value2";
	param3 = "value3";
	result = mini_printf("Example %s=%s and %s something %s", "\033[0;32m",
			param1, param2, param3);
	printf("%s\n", result); // No need to free memory since it's a static array
	return (0);
}
