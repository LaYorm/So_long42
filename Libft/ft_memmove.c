/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:17:38 by yorimek           #+#    #+#             */
/*   Updated: 2025/11/17 12:03:49 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*ptr_src;
	unsigned char		*ptr_dest;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	ptr_dest = (unsigned char *)dest;
	ptr_src = (const unsigned char *)src;
	if (dest < src || dest >= src + n)
	{
		i = 0;
		while (i < n)
		{
			ptr_dest[i] = ptr_src[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
		{
			ptr_dest[n] = ptr_src[n];
		}
	}
	return (dest);
}
