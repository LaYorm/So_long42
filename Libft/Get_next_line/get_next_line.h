/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:11:43 by yorimek           #+#    #+#             */
/*   Updated: 2025/12/12 15:03:19 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

// Includes

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft.h"

//   Main Functions

char	*get_next_line(int fd);
char	*ft_read_file(int fd, char *stock);
char	*ft_extract_line(char *str);
char	*ft_save_rest(char *str);

//    Utils functions

int		ft_has_new_line(char	*str, int searchedChar);
char	*ft_strjoin_gnl(char *stock, char *buff);

#endif