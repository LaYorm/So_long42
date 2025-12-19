/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:26:50 by yorimek           #+#    #+#             */
/*   Updated: 2025/12/19 14:42:18 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_which_image(t_data *data, t_map_data *map_data, int i, int j)
{
	if (map_data->map[j][i] == WALL)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->wall, i * 32, j * 32);
	if (map_data->map[j][i] == EXIT)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->exit, i * 32, j * 32);
	if (map_data->map[j][i] == FLOOR)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->floor, i * 32, j * 32);
	if (map_data->map[j][i] == PLAYER)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->p_current, i * 32, j * 32);
	if (map_data->map[j][i] == ITEMS)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->item, i * 32, j * 32);
}

void	ft_put_image_wnd(t_data *data, t_map_data *map_data)
{
	int	i;
	int	j;

	j = 0;
	while (map_data->map[j])
	{
		i = 0;
		while (map_data->map[j][i])
		{	
			ft_which_image(data, map_data, i, j);
			i++;
		}
		j++;
	}
}

void	ft_init_textures(t_data *data)
{
	int	x;
	int	y;

	data->p_down = mlx_xpm_file_to_image(data->mlx_ptr, P_DOWN, &x, &y);
	data->p_up = mlx_xpm_file_to_image(data->mlx_ptr, P_UP, &x, &y);
	data->p_left = mlx_xpm_file_to_image(data->mlx_ptr, P_LEFT, &x, &y);
	data->p_right = mlx_xpm_file_to_image(data->mlx_ptr, P_RIGHT, &x, &y);
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr, IMG_EXIT, &x, &y);
	data->item = mlx_xpm_file_to_image(data->mlx_ptr, IMG_ITEM, &x, &y);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, IMG_WALL, &x, &y);
	data->floor = mlx_xpm_file_to_image(data->mlx_ptr, IMG_FLOOR, &x, &y);
	if (!data->exit | !data->floor || !data->item || !data->p_down
		|| !data->p_left || !data->p_up || !data->p_right || !data->wall)
	{
		ft_printf("Could not load an xmp images. Check paths and filenames\n");
		ft_close_game(data);
	}
	data->p_current = data->p_down;
}
