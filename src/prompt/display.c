/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:25:36 by johmatos          #+#    #+#             */
/*   Updated: 2023/02/08 19:44:35 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
	char	*aux;
	char	*folder;
	int		len;

	arr = ft_split(pwd, '/');
	len = 0;
	while (arr[len] != NULL)
		len++;
	folder = ft_strdup(arr[len - 1]);
	while (len != -1)
		free(arr[len--]);
	free(arr);
	return (folder);
}

static char	*format_prompt(char *name, char *path)
{
	char	*prompt;
	int		len;

	path = format_path(path);
	len = ft_strlen(name) + 1;
	prompt = ft_calloc(1, ft_strlen(name) + ft_strlen(path + 1) + PREFIX_LEN);
	prompt[0] = '[';
	ft_strlcat(prompt, name, len + 1);
	prompt[len] = ']';
	prompt[++len] = ' ';
	prompt[++len] = '-';
	prompt[++len] = ' ';
	prompt[++len] = '[';
	ft_strlcat(prompt, path, ft_strlen(prompt) + len + PREFIX_LEN + 1);
	len = ft_strlen(prompt);
	prompt[len] = ']';
	prompt[++len] = ':';
	prompt[++len] = ' ';
	prompt[++len] = '\0';
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
