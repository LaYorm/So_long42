/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:56:17 by yorimek           #+#    #+#             */
/*   Updated: 2025/12/22 13:17:04 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_end_game(t_data *data, int x, int y)
{
	if (data->map_data->map[y][x] == EXIT && !data->map_data->collec)
	{
		ft_printf("Congratulations, you finished the game !!!!\n");
		ft_close_game(data);
	}
	if (data->map_data->map[y][x] == ENEMY)
	{
		ft_printf("Game Over ! You were defeated by an enemy !!\n");
		ft_close_game(data);
	}
	return ;
}

void	ft_check_move_utils(t_data *data, int x, int y)
{
	if (x == 0 && y == -1)
		data->p_current = data->p_up;
	if (x == 0 && y == 1)
		data->p_current = data->p_down;
	if (x == 1 && y == 0)
		data->p_current = data->p_right;
	if (x == -1 && y == 0)
		data->p_current = data->p_left;
}

void	ft_check_move(t_data *data, int x, int y)
{
	int	p_x;
	int	p_y;

	p_x = data->map_data->p_pos_x;
	p_y = data->map_data->p_pos_y;
	if (data->map_data->map[p_y + y][p_x + x] != WALL)
	{
		if (data->map_data->map[p_y + y][p_x + x] == ITEMS)
		{
			data->map_data->collec--;
			data->map_data->map[p_y + y][p_x + x] = FLOOR;
		}
		data->map_data->p_pos_x += x;
		data->map_data->p_pos_y += y;
		ft_check_move_utils(data, x, y);
		data->nb_mvt++;
		ft_print_moves(data);
	}
	return ;
}

void	ft_change_image(t_data *data, int old_x, int old_y)
{
	int	new_x;
	int	new_y;

	new_x = data->map_data->p_pos_x;
	new_y = data->map_data->p_pos_y;
	if (old_x != data->map_data->p_pos_x || old_y != data->map_data->p_pos_y)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->p_current,
			new_x * 32, new_y * 32);
		if (data->map_data->map[old_y][old_x] == EXIT)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit,
				old_x * 32, old_y * 32);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor,
				old_x * 32, old_y * 32);
	}
	return ;
}

int	ft_handle_input(int keysym, t_data *data)
{
	int	old_x;
	int	old_y;

	old_x = data->map_data->p_pos_x;
	old_y = data->map_data->p_pos_y;
	if (keysym == XK_Escape)
		ft_close_game(data);
	if (keysym == XK_Up || keysym == XK_w)
		ft_check_move(data, 0, -1);
	if (keysym == XK_Down || keysym == XK_s)
		ft_check_move(data, 0, 1);
	if (keysym == XK_Right || keysym == XK_d)
		ft_check_move(data, 1, 0);
	if (keysym == XK_Left || keysym == XK_a)
		ft_check_move(data, -1, 0);
	ft_change_image(data, old_x, old_y);
	ft_end_game(data, data->map_data->p_pos_x, data->map_data->p_pos_y);
	return (0);
}
