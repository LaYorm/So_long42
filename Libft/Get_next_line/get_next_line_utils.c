/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:47:38 by yorimek           #+#    #+#             */
/*   Updated: 2025/12/12 17:50:03 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_has_new_line(char	*str, int searchedChar)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == (char)searchedChar)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *stock, char *buff)
{
	int		i;
	int		j;
	char	*temp;

	if (!stock)
	{
		stock = ft_calloc(1, 1);
		if (!stock)
			return (NULL);
	}
	if (!buff)
		return (NULL);
	temp = malloc(sizeof(char) * (ft_strlen(stock) + ft_strlen(buff)) + 1);
	if (!temp)
		return (NULL);
	i = -1;
	while (stock[++i])
		temp[i] = stock[i];
	j = 0;
	while (buff[j])
		temp[i++] = buff[j++];
	temp[i] = '\0';
	free(stock);
	return (temp);
}
