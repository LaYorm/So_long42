/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:39:34 by yorimek           #+#    #+#             */
/*   Updated: 2025/12/12 17:49:26 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *stock)
{
	char	*buffer;
	int		bytes_read;

	if (!stock)
		stock = ft_calloc(1, 1);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_has_new_line(stock, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(stock);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stock = ft_strjoin_gnl(stock, buffer);
	}
	free(buffer);
	return (stock);
}

char	*ft_extract_line(char *str)
{
	char	*line;
	int		i;

	if (!str || str[0] == '\0')
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + ft_has_new_line(str, '\n') + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_save_rest(char *str)
{
	char	*save;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	save = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!save)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		save[j++] = str[i++];
	save[j] = '\0';
	free(str);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	stock = ft_read_file(fd, stock);
	if (!stock)
		return (NULL);
	line = ft_extract_line(stock);
	if (!line)
	{
		if (stock)
		{
			free(stock);
			stock = NULL;
		}
		return (NULL);
	}
	stock = ft_save_rest(stock);
	return (line);
}
// #include <fcntl.h>
// #include <stdio.h>
// int	main(void)
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	char *line;

// 	if (fd == -1)
// 		return (1);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	printf("\n");
// 	close(fd);
// 	return (0);
// }
