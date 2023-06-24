/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:01:14 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/23 17:01:33 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

int	change_directory(const char *path)
{
	if (chdir(path) == -1)
	{
		perror("cd");
		return (-1);
	}
	return (0);
}
//
// int	main(int argc, char *argv[])
// {
// 	if (argc < 2)
// 	{
// 		fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
// 		return (1);
// 	}
// 	if (change_directory(argv[1]) == -1)
// 		return (1);
// 	system("pwd");
// }
