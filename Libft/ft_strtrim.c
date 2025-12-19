/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:16:32 by yorimek           #+#    #+#             */
/*   Updated: 2025/11/17 14:37:11 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && !ft_isset(s1[start], set))
		start++;
	while (end > start && !ft_isset(s1[end - 1], set))
		end--;
	ptr = (char *)malloc(sizeof(char) * ((end - start) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[start] && start < end)
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}
