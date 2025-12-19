/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:19:33 by yorimek           #+#    #+#             */
/*   Updated: 2025/11/17 09:19:34 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	return (0);
}

// #include <stdio.h>
// int	main (int argc, char **argv)
// {
// 	if (argc != 2)
// 		return (0);
// 	printf("%d\n", ft_isalnum(argv[1][0]));
// }
