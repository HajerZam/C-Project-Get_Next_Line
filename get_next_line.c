/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:46:01 by halzamma          #+#    #+#             */
/*   Updated: 2025/01/07 14:39:06 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

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
	if (!line)
		return (NULL);
	if ((*stash)[i] == '\n')
		new_stash = ft_strdup(&(*stash)[i + 1]);
	else
		new_stash = NULL;
	free(*stash);
	*stash = new_stash;
	return (line);
}

static char	*allocate_buffer(void)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	return (buffer);
}

static char	*read_to_stash(int fd, char *stash)
{
	char	*buffer;

	if (!stash)
		stash = ft_strdup("");
	buffer = allocate_buffer();
	if (!buffer)
		return (NULL);
	stash = read_and_join(fd, buffer, stash);
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(&stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
	}
	return (line);
}

/*int	main(void)
{
	FILE *fd = fopen("wizard_test.txt", "r");
	char Buffer[255];

	while (fgets(Buffer, 255, fd))
	{
		printf("%s", Buffer);
	}
	fclose(fd);
	return (0);
}*/
