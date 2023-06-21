/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:14:16 by johmatos          #+#    #+#             */
/*   Updated: 2023/04/17 18:31:13 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*shift_left(char *buffer)
{
	size_t	count;
	size_t	shift;
	char	*new_buffer;

	shift = 0;
	count = -1;
	if (!buffer)
		return (NULL);
	while (buffer[shift] && buffer[shift] != '\n')
		shift++;
	new_buffer = malloc(sizeof(char) * ft_strlen(buffer) + 1);
	if (!new_buffer)
		return (NULL);
	while (buffer[shift])
		new_buffer[++count] = buffer[++shift];
	new_buffer[++count] = '\0';
	free (buffer);
	return (new_buffer);
}

char	*get_linex(char *buffer)
{
	size_t	shleft;
	size_t	count;
	char	*line;

	shleft = 0;
	count = 0;
	if (!buffer)
		return (NULL);
	if (!*buffer)
		return (NULL);
	while (buffer[shleft] && buffer[shleft] != '\n')
		shleft++;
	line = malloc((shleft + 2) * sizeof(char));
	if (!line)
		return (NULL);
	while (count <= shleft)
	{
		line[count] = buffer[count];
		count++;
	}
	line[count] = '\0';
	return (line);
}

char	*buffer_handler(char *buffer, int fd)
{
	char	*temp;
	char	*switch_aux;
	int		r_bytes;

	r_bytes = 1;
	temp = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!temp)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && r_bytes != 0)
	{
		r_bytes = read(fd, temp, BUFFER_SIZE);
		if (r_bytes < 0)
		{
			free (temp);
			return (NULL);
		}
		temp[r_bytes] = '\0';
		switch_aux = ft_new_buffer(buffer, temp);
		free (buffer);
		buffer = switch_aux;
	}
	free (temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;

	buffer = NULL;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	buffer = buffer_handler(buffer, fd);
	line = get_linex(buffer);
	buffer = shift_left(buffer);
	if (!buffer)
	{
		free (buffer);
		buffer = NULL;
		return (buffer);
	}
	return (line);
}
