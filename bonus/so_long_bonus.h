/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:09:48 by yorimek           #+#    #+#             */
/*   Updated: 2025/12/22 13:18:33 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

//-------------Includes-------------//

# include "Libft/libft.h"
# include "Libft/ft_printf/ft_printf.h"
# include "Libft/Get_next_line/get_next_line.h"
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>

//-------------Attribution----------//

# define WALL '1'
# define PLAYER 'P'
# define ITEMS 'C'
# define EXIT 'E'
# define FLOOR '0'
# define ENEMY 'M'

//-------------Error Messages-------//
# define PATH_WRONG "Map is unsolvable: Collectable(s) or End are unreachable !"
# define NOT_RECT "Error\nMap is not rectangle !"
# define NO_WALL "Error\nMap is missing wall(s) !"
# define WRONG_CHAR "Error\nMap contains an unknown character !"
# define NO_COLLECTIBLES "Error\nMap has too few collectibles !"
# define WRONG_EXIT "Error\nMap must contains exactly one exit !"
# define WRONG_PLAYER "Error\nMap must contain only one player !"
# define NO_ENEMY "Error\nMap must contain exactly one enemy !"

//-------------Path Image Attribution-------//
# define P_DOWN "textures/p_down.xpm"
# define P_UP "textures/p_up.xpm"
# define P_LEFT "textures/p_left.xpm"
# define P_RIGHT "textures/p_right.xpm"
# define IMG_EXIT "textures/exit.xpm"
# define IMG_ITEM "textures/item.xpm"
# define IMG_FLOOR "textures/floor.xpm"
# define IMG_WALL "textures/wall.xpm"
# define ENEMY_1 "textures/enemy_1.xpm"
# define ENEMY_2 "textures/enemy_2.xpm"
# define ENEMY_3 "textures/enemy_3.xpm"
# define ENEMY_4 "textures/enemy_4.xpm"
# define ENEMY_5 "textures/enemy_5.xpm"

//-------------Structures------------//

typedef struct s_map_data
{
	char	**map;
	int		width;
	int		height;
	int		collec;
	int		player;
	int		exit;
	int		p_pos_x;
	int		p_pos_y;
	int		enemy;
	int		e_pos_x;
	int		e_pos_y;
	int		e_dir;
}	t_map_data;

typedef struct s_data
{
	t_map_data	*map_data;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*wall;
	void		*floor;
	void		*exit;
	void		*item;
	void		*p_up;
	void		*p_down;
	void		*p_left;
	void		*p_right;
	void		*enemy_img[5];
	void		*p_current;
	int			nb_mvt;
}	t_data;

//-------------Functions------------//

int		main(int argc, char **argv);

void	ft_list_to_char(t_list *map_list, t_map_data *data);
t_list	*ft_get_map(char *map);
int		ft_map_is_ber(char *file, char *to_find);
void	ft_free_map(char **map);
int		ft_malloc_line(t_list *map_list, t_map_data *data);

//-------------Check Error/Free Functions------//

int		ft_check_error(t_map_data *data);
int		ft_error_and_free(t_map_data *data, char *msg);
void	ft_destroy_image(t_data *data);
void	ft_free_enemy_img(t_data *data);

//-------------Check Map Functions------//

int		ft_map_is_rectangle(t_map_data *data);
int		ft_map_has_wall(t_map_data *data);
int		ft_check_inside_map(t_map_data *data);
int		ft_check_element(t_map_data *data, int i, int j);

//-------------Path_Check Functions-----//

char	**ft_copy_map(char **map);
int		ft_map_is_solvable(t_map_data *data);
void	ft_flood_fill(char **map_copy, t_map_data *data, int x, int y);

//-------------Game Functions-----//

int		ft_handle_input(int keysym, t_data *data);
int		ft_close_game(t_data *data);
void	ft_init_textures(t_data *data);
void	ft_put_image_wnd(t_data *data, t_map_data *map_data);
void	ft_which_image(t_data *data, t_map_data *map_data, int i, int j);
void	ft_check_move(t_data *data, int x, int y);
void	ft_check_move_utils(t_data *data, int x, int y);
void	ft_end_game(t_data *data, int x, int y);
void	ft_move_ennemy(t_data *data);
void	ft_print_moves(t_data *data);
int		ft_animation_game(t_data *data);

//-------------Utils Functions-----//

void	ft_map_dimension(t_map_data *data);
void	ft_initialize_struct(t_map_data *map_data, t_data *data);
void	ft_lunch_game(t_data *game, t_map_data *map_data);
void	ft_get_map_ready(t_list *map_path, t_map_data *map_data, t_data *game);

#endif