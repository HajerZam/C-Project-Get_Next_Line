#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd1 = open("soldier.txt", O_RDONLY);
	int		fd2 = open("poet.txt", O_RDONLY);
	int		fd3 = open("king.txt", O_RDONLY);
	char	*line;

	static char	*stashes[FD_SETSIZE]; // Add this to track stashes for cleanup

	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
	{
		perror("Error opening one or more files");
		return (1);
	}
	printf("Files opened successfully\n");

	for (int i = 0; i < 5; i++) // Assuming each file has 5 lines
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

	// Cleanup remaining stashes
	free_stashes(stashes, FD_SETSIZE);

	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
