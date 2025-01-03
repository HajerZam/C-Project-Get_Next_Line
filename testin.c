#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd1 = open("soldier.txt", O_RDONLY);
	int		fd2 = open("poet.txt", O_RDONLY);
	int		fd3 = open("king.txt", O_RDONLY);
	char	*line;

	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
	{
		perror("Error opening file");
		return (1);
	}
	for (int i = 0; i < 5; i++) // Assuming 5 lines in each file
	{
		if ((line = get_next_line(fd1)))
		{
			printf("Soldier: %s", line);
			free(line);
		}
		if ((line = get_next_line(fd2)))
		{
			printf("Poet: %s", line);
			free(line);
		}
		if ((line = get_next_line(fd3)))
		{
			printf("King: %s", line);
			free(line);
		}
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
