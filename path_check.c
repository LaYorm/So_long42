/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:58:37 by yorimek           #+#    #+#             */
/*   Updated: 2025/12/19 13:57:37 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_copy_map(char **map)
{
	char	**copy;
	int		nb_line;

	nb_line = 0;
	while (map[nb_line])
		nb_line++;
	copy = (char **)malloc(sizeof(char *) * (nb_line + 1));
	if (!copy)
		return (NULL);
	nb_line = 0;
	while (map[nb_line])
	{
		copy[nb_line] = ft_strdup((const char *)map[nb_line]);
		if (!copy[nb_line])
		{
			ft_free_map(copy);
			return (NULL);
		}
		nb_line++;
	}
	copy[nb_line] = NULL;
	return (copy);
}

void	ft_flood_fill(char **map_copy, t_map_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->width || y >= data->height
		|| map_copy[y][x] == WALL || map_copy[y][x] == '~')
		return ;
	map_copy[y][x] = '~';
	ft_flood_fill(map_copy, data, x + 1, y);
	ft_flood_fill(map_copy, data, x - 1, y);
	ft_flood_fill(map_copy, data, x, y + 1);
	ft_flood_fill(map_copy, data, x, y - 1);
}

int	ft_map_is_solvable(t_map_data *data)
{
	char	**map_copy;
	int		i;
	int		j;

	map_copy = ft_copy_map(data->map);
	if ((!map_copy))
		return (0);
	ft_flood_fill(map_copy, data, data->p_pos_x, data->p_pos_y);
	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == ITEMS || map_copy[i][j] == EXIT)
			{
				ft_free_map(map_copy);
				return (0);
			}
			j++;
		}
		i++;
	}
	ft_free_map(map_copy);
	return (1);
}
