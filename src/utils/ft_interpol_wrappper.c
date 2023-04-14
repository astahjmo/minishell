/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpol_wrappper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:09:36 by johmatos          #+#    #+#             */
/*   Updated: 2023/04/12 19:14:50 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_interpol_wrappper(char *pattern, ...)
{
	char	*str;
	va_list	args;
	str = ft_interpol(pattern, args);
}
