/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:57:49 by yorimek           #+#    #+#             */
/*   Updated: 2025/12/22 10:11:06 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free_map(char **map)
{
	char	**mem;
	int		i;

	i = 0;
	mem = map;
	if (map == NULL)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(mem);
}

int	ft_malloc_line(t_list *map_list, t_map_data *data)
{
	int		line;
	char	*new_line_position;

	line = 0;
	while (map_list)
	{
		new_line_position = ft_strchr((const char *)map_list->content, '\n');
		if (new_line_position)
			*new_line_position = '\0';
		data->map[line] = ft_strdup((const char *)map_list->content);
		if (!data->map[line])
		{
			ft_free_map(data->map);
			return (0);
		}
		map_list = map_list->next;
		line++;
	}
	data->map[line] = NULL;
	return (1);
}

void	ft_list_to_char(t_list *map_list, t_map_data *data)
{
	int		size_list;

	size_list = ft_lstsize(map_list);
	data->map = (char **)malloc(sizeof(char *) * (size_list + 1));
	if (!data->map)
		return ;
	if (!ft_malloc_line(map_list, data))
		return ;
}

t_list	*ft_get_map(char *map_path)
{
	t_list	*map_list;
	t_list	*new_line;
	char	*line;
	int		fd;

	map_list = NULL;
	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		new_line = ft_lstnew(line);
		if (!new_line)
		{
			free(line);
			ft_lstclear(&map_list, free);
			return (NULL);
		}
		ft_lstadd_back(&map_list, new_line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map_list);
}
