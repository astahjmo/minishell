/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth <astaroth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:43:44 by astaroth          #+#    #+#             */
/*   Updated: 2023/05/16 15:28:33 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

long long int	hash_map(char *string)
{
	long long	hashing;
	long long	pow;
	int			count;
	static int	module = 1e4;

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
