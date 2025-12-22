/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:08:36 by yorimek           #+#    #+#             */
/*   Updated: 2025/12/22 13:14:48 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_print_moves(t_data *data)
{
	int		i;
	char	*nb_mvts;
	char	*print_mouv;

	i = 0;
	nb_mvts = ft_itoa(data->nb_mvt);
	print_mouv = ft_strjoin("Nbr of mvts: ", nb_mvts);
	while (i < data->map_data->width)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->wall, i * 32, 0);
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall, 0, 0);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 20, 0xFF0000, print_mouv);
	free (nb_mvts);
	free (print_mouv);
}

void	ft_move_ennemy(t_data *data)
{
	static int	timer = 0;
	int			e_x;
	int			e_y;

	if (timer++ < 15000)
		return ;
	timer = 0;
	e_x = data->map_data->e_pos_x;
	e_y = data->map_data->e_pos_y;
	if (data->map_data->map[e_y + data->map_data->e_dir][e_x] != FLOOR)
	{
		data->map_data->e_dir *= -1;
		return ;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->floor, e_x * 32, e_y * 32);
	data->map_data->map[e_y][e_x] = FLOOR;
	e_y += data->map_data->e_dir;
	data->map_data->e_pos_y += data->map_data->e_dir;
	data->map_data->map[e_y][e_x] = ENEMY;
	return ;
}

void	ft_change_img_enemy(t_data *data)
{
	static int	timer = 0;
	static int	frame = 0;
	int			e_x;
	int			e_y;

	if (timer++ < 2500)
		return ;
	timer = 0;
	e_x = data->map_data->e_pos_x;
	e_y = data->map_data->e_pos_y;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->enemy_img[frame], e_x * 32, e_y * 32);
	frame++;
	if (frame >= 5)
		frame = 0;
}

int	ft_animation_game(t_data *data)
{
	ft_move_ennemy(data);
	ft_change_img_enemy(data);
	ft_end_game(data, data->map_data->p_pos_x, data->map_data->p_pos_y);
	return (0);
}
