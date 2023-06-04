/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth <astaroth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:43:44 by astaroth          #+#    #+#             */
/*   Updated: 2023/06/04 06:01:31 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

long long int	hash_map(char *string)
{
	long long	hashing;
	long long	pow;
	int			count;
	static int	module = 1e3;

	count = 0;
	pow = 1;
	hashing = 0;
	while (string[count])
	{
		hashing = (hashing
				+ (string[count] - string[count + 1]) * pow) % module;
		pow = (pow * 373) % module;
		count++;
	}
	return (hashing);
}
