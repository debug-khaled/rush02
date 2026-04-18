#include "team.h"

int	file_size(char *dict_path)
{
	int	fd;
	int	size;
	char	c;

	size = 0;
	fd = open(dict_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (read(fd, &c, 1) > 0)
		size++;
	close(fd);
	return (size);
}

char	*read_file(char *dict_path)
{
	int	fd;
	int	size;
	char	*buffer;

	size = file_size(dict_path);
	if (size <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char)) * (size + 1));
	if (!buffer)
		return (NULL);
	fd = open(dict_path, O_RDONLY);
	if (fd == = -1)
	{
		free(buffer);
		return (NULL);
	}
	read(fd, buffer, size);
	buffer[size] = '\0';
	close(fd);
	return (buffer);
}
















