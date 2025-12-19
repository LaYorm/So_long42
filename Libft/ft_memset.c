/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:17:31 by yorimek           #+#    #+#             */
/*   Updated: 2025/11/17 09:17:33 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)pointer;
	while (i < count)
	{
		ptr[i] = value;
		i++;
	}
	return (pointer);
}
