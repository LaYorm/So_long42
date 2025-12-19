/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:55:55 by yorimek           #+#    #+#             */
/*   Updated: 2025/12/19 14:11:27 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error_and_free(t_map_data *data, char *msg)
{
	ft_printf("%s\n", msg);
	if (data)
	{
		if (data->map)
			ft_free_map(data->map);
		free(data);
	}
	return (1);
}

int	ft_check_error(t_map_data *data)
{
	int	save_res_check;

	if (!ft_map_is_rectangle(data))
		return (ft_error_and_free(data, NOT_RECT));
	if (!ft_map_has_wall(data))
		return (ft_error_and_free(data, NO_WALL));
	save_res_check = ft_check_inside_map(data);
	if (!save_res_check)
		return (ft_error_and_free(data, WRONG_CHAR));
	if (save_res_check == 2)
		return (ft_error_and_free(data, NO_COLLECTIBLES));
	if (save_res_check == 3)
		return (ft_error_and_free(data, WRONG_EXIT));
	if (save_res_check == 4)
		return (ft_error_and_free(data, WRONG_PLAYER));
	if (!ft_map_is_solvable(data))
		return (ft_error_and_free(data, PATH_WRONG));
	return (0);
}

int	ft_close_game(t_data *data)
{
	if (data->floor)
		mlx_destroy_image(data->mlx_ptr, data->floor);
	if (data->exit)
		mlx_destroy_image(data->mlx_ptr, data->exit);
	if (data->p_down)
		mlx_destroy_image(data->mlx_ptr, data->p_down);
	if (data->p_left)
		mlx_destroy_image(data->mlx_ptr, data->p_left);
	if (data->p_up)
		mlx_destroy_image(data->mlx_ptr, data->p_up);
	if (data->p_right)
		mlx_destroy_image(data->mlx_ptr, data->p_right);
	if (data->item)
		mlx_destroy_image(data->mlx_ptr, data->item);
	if (data->wall)
		mlx_destroy_image(data->mlx_ptr, data->wall);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free (data->mlx_ptr);
	ft_error_and_free(data->map_data, "Game has been close properly !");
	exit (0);
	return (0);
}
