/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:18:51 by yorimek           #+#    #+#             */
/*   Updated: 2025/11/17 14:38:08 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_nb(long n)
{
	int		size_n;

	size_n = 0;
	if (n <= 0)
	{
		n *= (-1);
		size_n++;
	}
	while (n > 0)
	{
		n /= 10;
		size_n++;
	}
	return (size_n);
}

char	*ft_itoa(int n)
{
	char	*tab;
	int		size_n;
	int		close;
	long	nbr;

	nbr = n;
	size_n = ft_size_nb(nbr);
	close = size_n;
	if (nbr < 0)
		nbr *= (-1);
	tab = (char *)malloc(sizeof(char) * (size_n + 1));
	if (!tab)
		return (NULL);
	while (nbr >= 0 && size_n > 0)
	{
		tab[size_n - 1] = (nbr % 10) + '0';
		nbr /= 10;
		size_n--;
	}
	if (n < 0)
		tab[0] = '-';
	tab[close] = '\0';
	return (tab);
}
