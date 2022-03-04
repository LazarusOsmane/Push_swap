#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char *ft_str(char *line, char *buf, int len)
{
	int i;
	char *new;

	if (!line)
	{
		line = malloc(sizeof(char) * 2);
		if (!line)
			return (NULL);
		line[0] = *buf;
		line[1] = '\0';
		return (line);
	}
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = -1; 
	while (line[++i])
		new[i] = line[i];
	new[i++] = buf[0];
	new[i] = '\0';
	if (line)
		free(line);
	return (new);
}

char *read_output()
{
	int	i;
	int ret;
	char buf[1];
	char *line;

	i = 1;
	ret = 1;
	buf[0] = '\0';
	line = NULL;
	while ((ret = read(1, buf, 1)) > 0)
	{
		line = ft_str(line, buf, i);
		if (buf[0] == '\n')
			break;
		i++;
	}
	if (ret >= 0 && line)
		return (line);
	return (NULL);
}
