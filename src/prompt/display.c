/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:25:36 by johmatos          #+#    #+#             */
/*   Updated: 2023/05/13 17:36:31 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_user_env(void)
{
	char	*user;

	user = getenv("USER");
	if (!user)
		user = getenv("LOGNAME");
	return (user);
}

static char	*format_path(char *pwd)
{
	char	**arr;
	char	*folder;
	int		len;

	arr = ft_split(pwd, '/');
	len = 0;
	while (arr[len] != NULL)
		len++;
	if (len == 0)
	{
		free(arr);
		return (ft_strdup("/"));
	}
	folder = ft_strdup(arr[len - 1]);
	while (len != -1)
		free(arr[len--]);
	free(arr);
	return (folder);
}

static char	*format_prompt(char *name, char *path)
{
	char	*prompt;

	path = format_path(path);
	prompt = fmt_s(CYAN "[%s] - [%s]-> " RESET, name, path, NULL);
	free(path);
	return (prompt);
}

static char	*get_pwd(char *path)
{
	getcwd(path, PATH_MAX);
	return (path);
}

char	*get_prompt(void)
{
	char	pwd[PATH_MAX];
	char	*user;
	char	*prompt;

	user = get_user_env();
	get_pwd(pwd);
	prompt = format_prompt(user, pwd);
	return (prompt);
}
