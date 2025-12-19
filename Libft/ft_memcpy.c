/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:17:45 by yorimek           #+#    #+#             */
/*   Updated: 2025/11/17 11:46:21 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*ptr_src;
	unsigned char		*ptr_dest;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	ptr_src = (const unsigned char *) src;
	ptr_dest = (unsigned char *) dest;
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (dest);
}
