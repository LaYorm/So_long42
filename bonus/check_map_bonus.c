/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:50:55 by yorimek           #+#    #+#             */
/*   Updated: 2025/12/22 12:20:55 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_element(t_map_data *data, int i, int j)
{
	while (data->map[i][j] && j < data->width)
	{
		if (data->map[i][j] != ITEMS && data->map[i][j] != EXIT
			&& data->map[i][j] != PLAYER && data->map[i][j] != WALL
				&& data->map[i][j] != FLOOR && data->map[i][j] != ENEMY)
			return (0);
		if (data->map[i][j] == ITEMS)
			data->collec++;
		if (data->map[i][j] == PLAYER)
		{
			data->p_pos_x = j;
			data->p_pos_y = i;
			data->player++;
		}
		if (data->map[i][j] == EXIT)
			data->exit++;
		if (data->map[i][j] == ENEMY)
		{
			data->enemy++;
			data->e_pos_x = j;
			data->e_pos_y = i;
		}
		j++;
	}
	return (1);
}

int	ft_check_inside_map(t_map_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (data->map[i] && i < data->height)
	{
		j = 1;
		if (!ft_check_element(data, i, j))
			return (0);
		i++;
	}
	if (data->collec < 1)
		return (2);
	if (data->exit != 1)
		return (3);
	if (data->player != 1)
		return (4);
	if (data->enemy != 1)
		return (5);
	return (1);
}

int	ft_map_has_wall(t_map_data *data)
{
	int	i;

	i = 0;
	ft_map_dimension(data);
	while (i < data->width)
	{
		if (data->map[0][i] != WALL || data->map[data->height - 1][i] != WALL)
			return (0);
		i++;
	}
	i = 0;
	while (i < data->height)
	{
		if (data->map[i][0] != WALL || data->map[i][data->width - 1] != WALL)
			return (0);
		i++;
	}
	return (1);
}

int	ft_map_is_rectangle(t_map_data *data)
{
	size_t	size_line;
	int		i;

	i = 1;
	if (data->map == NULL || data->map[0] == NULL)
		return (0);
	size_line = ft_strlen(data->map[0]);
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) != size_line)
			return (0);
		i++;
	}
	return (1);
}

int	ft_map_is_ber(char *file, char *to_find)
{
	int	i;
	int	start;

	start = ft_strlen(file) - ft_strlen(to_find);
	i = 0;
	if (start < 1)
		return (0);
	while (file[start] && to_find[i] && file[start] == to_find[i])
	{
		start++;
		i++;
	}
	if (!file[start] && !to_find[i])
		return (1);
	ft_printf("Error\nMap is not .ber !\n");
	return (0);
}
