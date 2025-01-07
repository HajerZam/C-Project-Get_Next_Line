/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:04:12 by halzamma          #+#    #+#             */
/*   Updated: 2025/01/07 12:03:36 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

static char	*extract_line(char **stash)
{
	char	*line;
	char	*new_stash;
	size_t	i;

	if (!*stash || **stash == '\0')
		return (NULL);
	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	line = ft_substr(*stash, 0, i + ((*stash)[i] == '\n'));
	if ((*stash)[i])
		new_stash = ft_strdup(&(*stash)[i + 1]);
	else
		new_stash = ft_strdup("");
	free(*stash);
	*stash = new_stash;
	return (line);
}

static char	*read_to_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin_free(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stashs[FD_SETSIZE];

	if (fd < 0 || fd >= FD_SETSIZE || BUFFER_SIZE <= 0)
		return (NULL);
	stashs[fd] = read_to_stash(fd, stashs[fd]);
	if (!stashs[fd])
		return (NULL);
	return (extract_line(&stashs[fd]));
}
