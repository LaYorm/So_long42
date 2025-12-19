/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:17:57 by yorimek           #+#    #+#             */
/*   Updated: 2025/11/17 09:17:58 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned const char	*ptr;

	i = 0;
	ptr = (unsigned const char *)s;
	while (i < n)
	{
		if (ptr[i] == (unsigned const char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
