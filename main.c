#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"


void get_lines(int fd)
{
	char	*line;
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
}
int main(int ac, char **av)
{
	if (ac > 1)
	{
		int fd = open(av[1], O_RDONLY);
		get_lines(fd);
	}
	else
		get_lines(0);
}
