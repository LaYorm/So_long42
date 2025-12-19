/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:16:23 by yorimek           #+#    #+#             */
/*   Updated: 2025/11/17 09:16:26 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	size_s;

	size_s = ft_strlen(s);
	if (s[size_s] == (char)c)
		return ((char *)&s[size_s]);
	while (size_s >= 0)
	{
		if (s[size_s] == (char)c)
			return ((char *)&s[size_s]);
		size_s--;
	}
	return (NULL);
}
