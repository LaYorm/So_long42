/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:19:03 by yorimek           #+#    #+#             */
/*   Updated: 2025/11/17 09:19:04 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

// #include <stdio.h>
// int	main (int argc, char **argv)
// {
// 	if (argc != 2)
// 		return (0);
// 	printf("%d\n", ft_digit(argv[1][0]));
// }