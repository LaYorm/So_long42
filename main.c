/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:42:24 by yorimek           #+#    #+#             */
/*   Updated: 2025/12/19 14:56:25 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_list		*map_path;
	t_map_data	*map_data;
	t_data		*game;

	if (argc != 2 || !ft_map_is_ber(argv[1], ".ber"))
		return (ft_error_and_free(NULL, "Arguments needed: <./a.out> <*.ber>"));
	map_path = ft_get_map(argv[1]);
	map_data = (t_map_data *)malloc(sizeof(t_map_data));
	if (!map_data)
		return (1);
	game = (t_data *)malloc(sizeof(t_data));
	if (!game)
		return (1);
	ft_get_map_ready(map_path, map_data, game);
	ft_lunch_game(game, map_data);
}
