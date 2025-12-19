/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:00:56 by yorimek           #+#    #+#             */
/*   Updated: 2025/12/19 14:51:06 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initialize_struct(t_map_data *map_data, t_data *data)
{
	map_data->collec = 0;
	map_data->exit = 0;
	map_data->height = 0;
	map_data->width = 0;
	map_data->player = 0;
	map_data->p_pos_y = 0;
	map_data->p_pos_x = 0;
	data->wall = NULL;
	data->floor = NULL;
	data->exit = NULL;
	data->item = NULL;
	data->p_up = NULL;
	data->p_down = NULL;
	data->p_left = NULL;
	data->p_right = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->p_current = NULL;
	data->map_data = map_data;
	data->nb_mvt = 0;
}

void	ft_map_dimension(t_map_data *data)
{
	int	i;

	i = 0;
	data->width = ft_strlen(data->map[0]);
	while (data->map[i])
		i++;
	data->height = i;
}

void	ft_get_map_ready(t_list *map_path, t_map_data *map_data, t_data *game)
{
	ft_initialize_struct(map_data, game);
	ft_list_to_char(map_path, map_data);
	ft_lstclear(&map_path, free);
	if (ft_check_error(map_data) || !ft_map_is_solvable(map_data))
		exit(0);
}

void	ft_lunch_game(t_data *game, t_map_data *map_data)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, map_data->width * 32,
			map_data->height * 32, "So_Long");
	ft_init_textures(game);
	ft_put_image_wnd(game, map_data);
	mlx_key_hook(game->win_ptr, ft_handle_input, game);
	mlx_hook(game->win_ptr, 17, 0L, ft_close_game, game);
	mlx_loop(game->mlx_ptr);
}
