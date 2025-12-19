/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:19:43 by yorimek           #+#    #+#             */
/*   Updated: 2025/11/17 09:20:02 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (size != 0 && nmemb > __SIZE_MAX__ / size)
		return (NULL);
	tab = (void *)malloc(nmemb * size);
	if (!tab)
		return (NULL);
	ft_memset(tab, 0, nmemb * size);
	return (tab);
}
